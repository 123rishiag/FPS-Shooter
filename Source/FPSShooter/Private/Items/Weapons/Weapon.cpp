// FPSShooter


#include "Items/Weapons/Weapon.h"
#include "Components/SkeletalMeshComponent.h"

AWeapon::AWeapon()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCastShadow(false);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

