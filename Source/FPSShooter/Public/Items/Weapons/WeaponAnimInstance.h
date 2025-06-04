// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WeaponAnimInstance.generated.h"

class AWeapon;

/**
 * 
 */
UCLASS()
class FPSSHOOTER_API UWeaponAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY()
	AWeapon* Owner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|Booleans")
	bool bIsShooting;
};
