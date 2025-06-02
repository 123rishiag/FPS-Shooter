// FPSShooter


#include "Items/Weapons/Weapon.h"
#include "Components/SkeletalMeshComponent.h"

AWeapon::AWeapon()
{
 	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCastShadow(false);
}

void AWeapon::Shoot()
{

}

void AWeapon::EnableWeapon()
{
	SetActorHiddenInGame(false);
}

void AWeapon::DisableWeapon()
{
	SetActorHiddenInGame(true);
}

