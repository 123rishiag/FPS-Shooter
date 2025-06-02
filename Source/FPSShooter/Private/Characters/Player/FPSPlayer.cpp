// FPSShooter


#include "Characters/Player/FPSPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "Items/Weapons/Weapon.h"

AFPSPlayer::AFPSPlayer()
{
 	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	ArmsMesh->SetupAttachment(Camera);
	ArmsMesh->SetCastShadow(false);

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	AssignWeapons();
	SwitchWeapon(EWeaponType::EWT_Rifle);
}

void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLocomotionState();
	UpdateActionState();
}

void AFPSPlayer::UpdateLocomotionState()
{
	if (!GetCharacterMovement()->IsMovingOnGround())
	{
		LocomotionState = EFPSPlayerLocomotionState::EFPSPLS_Jump;
	}
	else if (bIsMoving)
	{
		if (bIsSprinting)
		{
			LocomotionState = EFPSPlayerLocomotionState::EFPSPLS_Sprint;
		}
		else
		{
			LocomotionState = EFPSPlayerLocomotionState::EFPSPLS_Walk;
		}
	}
	else
	{
		LocomotionState = EFPSPlayerLocomotionState::EFPSPLS_Idle;
	}
}

void AFPSPlayer::UpdateActionState()
{
	if (bIsAiming && bIsShooting)
	{
		ActionState = EFPSPlayerActionState::EFPSPAS_AimShoot;
	}
	else if (bIsShooting)
	{
		ActionState = EFPSPlayerActionState::EFPSPAS_Shoot;
	}
	else if (bIsAiming)
	{
		ActionState = EFPSPlayerActionState::EFPSPAS_Aim;
	}
	else
	{
		ActionState = EFPSPlayerActionState::EFPSPAS_None;
	}
}

void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSPlayer::Move);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Completed, this, &AFPSPlayer::StopMove);

		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSPlayer::Look);

		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AFPSPlayer::Jump);

		EnhancedInput->BindAction(AimAction, ETriggerEvent::Ongoing, this, &AFPSPlayer::Aim);
		EnhancedInput->BindAction(AimAction, ETriggerEvent::Completed, this, &AFPSPlayer::StopAim);

		EnhancedInput->BindAction(ShootAction, ETriggerEvent::Ongoing, this, &AFPSPlayer::Shoot);
		EnhancedInput->BindAction(ShootAction, ETriggerEvent::Completed, this, &AFPSPlayer::StopShoot);

		EnhancedInput->BindAction(SprintAction, ETriggerEvent::Ongoing, this, &AFPSPlayer::Sprint);
		EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFPSPlayer::StopSprint);
	}
}

void AFPSPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MoveInput = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), MoveInput.Y);
	AddMovementInput(GetActorRightVector(), MoveInput.X);

	bIsMoving = true;
}

void AFPSPlayer::StopMove()
{
	bIsMoving = false;
}

void AFPSPlayer::Look(const FInputActionValue& Value)
{
	FVector2D LookAxis = Value.Get<FVector2D>();
	AddControllerPitchInput(LookAxis.Y);
	AddControllerYawInput(LookAxis.X);

	FRotator CurrentRotation = Controller->GetControlRotation();
	float NewPitch = FMath::ClampAngle(CurrentRotation.Pitch + LookAxis.Y, -30.f, 30.f);

	FRotator ClampedRotation = FRotator(NewPitch, CurrentRotation.Yaw, CurrentRotation.Roll);
	Controller->SetControlRotation(ClampedRotation);
}

void AFPSPlayer::Sprint()
{
	if (ActionState == EFPSPlayerActionState::EFPSPAS_None)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		bIsSprinting = true;
	}
}

void AFPSPlayer::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bIsSprinting = false;
}

void AFPSPlayer::Jump()
{
	Super::Jump();
}

void AFPSPlayer::Aim()
{
	if(GetCharacterMovement()->IsMovingOnGround())
	{
		bIsAiming = true;
		StopSprint();
	}
}

void AFPSPlayer::StopAim()
{
	bIsAiming = false;
}

void AFPSPlayer::Shoot()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Shoot();
		bIsShooting = true;
		StopSprint();
	}
}

void AFPSPlayer::StopShoot()
{
	bIsShooting = false;
}

void AFPSPlayer::AssignWeapons()
{
	for (const FWeaponSlot& Slot : WeaponLoadout)
	{
		// Checking if Weapon is Assigned into player
		if (!Slot.Weapon)
		{
			continue;
		}

		// Checking if weapon was successfuly spawned
		AWeapon* NewWeapon = GetWorld()->SpawnActor<AWeapon>(Slot.Weapon);
		if (!NewWeapon)
		{
			continue;
		}
		NewWeapon->AttachToComponent(
			ArmsMesh, FAttachmentTransformRules::SnapToTargetIncludingScale,
			FName("GripPoint")
		);
		NewWeapon->SetOwner(this);
		NewWeapon->DisableWeapon();

		// Adding weapon to Dictionary
		EquippedWeapons.Add(Slot.WeaponType, NewWeapon);
	}
}

void AFPSPlayer::SwitchWeapon(EWeaponType WeaponType)
{
	if (CurrentWeapon)
	{
		CurrentWeapon->DisableWeapon();
	}

	if (AWeapon** FoundWeapon = EquippedWeapons.Find(WeaponType))
	{
		CurrentWeapon = *FoundWeapon;
		CurrentWeapon->EnableWeapon();
	}
}