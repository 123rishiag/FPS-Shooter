// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/Player/FPSPlayerState.h"
#include "FPSPlayerAnimInstance.generated.h"

class AFPSPlayer;

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
	AFPSPlayer* Owner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|Enum")
	EFPSPlayerLocomotionState LocomotionState = EFPSPlayerLocomotionState::EFPSPLS_Idle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|Enum")
	EFPSPlayerActionState ActionState = EFPSPlayerActionState::EFPSPAS_None;
};
