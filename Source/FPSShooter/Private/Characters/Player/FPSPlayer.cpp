// FPSShooter


#include "Characters/Player/FPSPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "Items/Weapons/Weapon.h"

AFPSPlayer::AFPSPlayer()
{
 	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	ArmsMesh->SetupAttachment(Camera);
	ArmsMesh->CastShadow = false;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	AssignWeapons();
	SwitchWeapon(EWeaponType::EWT_Rifle);
}

void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSPlayer::Move);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSPlayer::Look);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInput->BindAction(ShootAction, ETriggerEvent::Started, this, &AFPSPlayer::Shoot);
	}
}
void AFPSPlayer::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
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

void AFPSPlayer::Shoot()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Shoot();
	}
}

void AFPSPlayer::AssignWeapons()
{
	for (const FWeaponSlot& Slot : WeaponLoadout)
	{
		// Checking if Weapon is Assigned into player
		if (Slot.WeaponType == EWeaponType::EWT_None || !Slot.Weapon)
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
			TEXT("GripPoint")
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

	if (WeaponType == EWeaponType::EWT_None)
	{
		CurrentWeapon = nullptr;
	}

	if (AWeapon** FoundWeapon = EquippedWeapons.Find(WeaponType))
	{
		CurrentWeapon = *FoundWeapon;
		CurrentWeapon->EnableWeapon();
	}
}
