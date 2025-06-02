// FPSShooter


#include "Items/Weapons/WeaponRifle.h"

AWeaponRifle::AWeaponRifle()
{
	WeaponType = EWeaponType::EWT_Rifle;
}

void AWeaponRifle::Shoot()
{
	Super::Shoot();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Shoot called!"));
	}
}