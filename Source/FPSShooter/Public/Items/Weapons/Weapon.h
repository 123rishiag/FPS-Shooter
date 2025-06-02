// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/Weapons/WeaponType.h"
#include "Weapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class FPSSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	virtual void Shoot();
	void EnableWeapon();
	void DisableWeapon();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh;

	EWeaponType WeaponType = EWeaponType::EWT_None;

public:
	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; }
};
