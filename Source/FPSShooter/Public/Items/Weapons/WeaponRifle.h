// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/Weapon.h"
#include "WeaponRifle.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class FPSSHOOTER_API AWeaponRifle : public AWeapon
{
	GENERATED_BODY()
	
public:
	AWeaponRifle(); 

	virtual void Shoot() override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UStaticMeshComponent* ScopeMesh;
};
