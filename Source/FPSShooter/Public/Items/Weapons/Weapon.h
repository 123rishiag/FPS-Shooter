// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/Weapons/WeaponType.h"
#include "Weapon.generated.h"

class USkeletalMeshComponent;
class UFPSAimUserWidget;

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

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* WeaponMesh; 

	EWeaponType WeaponType;

private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UFPSAimUserWidget> AimWidgetClass;

	UPROPERTY()
	UFPSAimUserWidget* AimWidget;

public:
	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; }
};
