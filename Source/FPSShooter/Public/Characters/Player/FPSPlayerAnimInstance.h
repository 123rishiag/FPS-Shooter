// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSPlayerAnimInstance.generated.h"

class AFPSPlayer;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class FPSSHOOTER_API UFPSPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	AFPSPlayer* OwnerCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwnerMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bHasAcceleration;
};
