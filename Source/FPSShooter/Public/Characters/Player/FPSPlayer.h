// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Items/Weapons/WeaponType.h"
#include "FPSPlayer.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;
class UCharacterMovementComponent;
class UInputAction;
class AWeapon;

USTRUCT(BlueprintType)
struct FWeaponSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AWeapon> Weapon;
};

UCLASS()
class FPSSHOOTER_API AFPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSPlayer();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

#pragma region PlayerProperties

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion", meta = (AllowPrivateAccess = "true"))
	float WalkSpeed = 200.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Locomotion", meta = (AllowPrivateAccess = "true"))
	float SprintSpeed = 600.f;

#pragma endregion

#pragma region PlayerComponents

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* ArmsMesh;

#pragma endregion 

#pragma region Weapons

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TArray<FWeaponSlot> WeaponLoadout;

	TMap<EWeaponType, AWeapon*> EquippedWeapons;

	AWeapon* CurrentWeapon;

#pragma endregion

#pragma region Input

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ShootAction;

#pragma endregion

	// Action Functions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void SetWalkSpeed();
	void SetSprintSpeed();
	void Shoot();
	void AssignWeapons();
	void SwitchWeapon(EWeaponType WeaponType);
};
