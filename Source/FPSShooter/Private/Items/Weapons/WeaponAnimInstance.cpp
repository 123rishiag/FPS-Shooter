// FPSShooter


#include "Items/Weapons/WeaponAnimInstance.h"
#include "Items/Weapons/Weapon.h"

void UWeaponAnimInstance::NativeInitializeAnimation()
{
	Owner = Cast<AWeapon>(TryGetPawnOwner());

}

void UWeaponAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!Owner)
	{
		return;
	}

	bIsShooting = Owner->GetIsShooting();
}
