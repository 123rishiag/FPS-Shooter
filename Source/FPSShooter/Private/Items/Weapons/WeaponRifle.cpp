// FPSShooter


#include "Items/Weapons/WeaponRifle.h"
#include "Components/StaticMeshComponent.h"

AWeaponRifle::AWeaponRifle()
{
	WeaponType = EWeaponType::EWT_Rifle;
	
	if (WeaponMesh)
	{
		ScopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scope"));
		ScopeMesh->AttachToComponent(WeaponMesh, FAttachmentTransformRules::SnapToTargetIncludingScale,
			FName("ScopeSocket"));
		ScopeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AWeaponRifle::Shoot()
{
	Super::Shoot();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Shoot called!"));
	}
}