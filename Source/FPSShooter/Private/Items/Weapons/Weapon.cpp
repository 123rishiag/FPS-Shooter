// FPSShooter


#include "Items/Weapons/Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "HUD/FPSAimUserWidget.h"

AWeapon::AWeapon()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCastShadow(false);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bIsShooting = false;
}

void AWeapon::BeginPlay()
{
	if (AimWidgetClass)
	{
		AimWidget = CreateWidget<UFPSAimUserWidget>(GetWorld(), AimWidgetClass);
		if (AimWidget)
		{
			AimWidget->AddToViewport();
			AimWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void AWeapon::Shoot()
{
	bIsShooting = true;
}

void AWeapon::EnableWeapon()
{
	SetActorHiddenInGame(false);
}

void AWeapon::DisableWeapon()
{
	SetActorHiddenInGame(true);
}

