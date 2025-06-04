// FPSShooter


#include "Characters/Player/FPSPlayerAnimInstance.h"
#include "Characters/Player/FPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFPSPlayerAnimInstance::NativeInitializeAnimation()
{
	Owner = Cast<AFPSPlayer>(TryGetPawnOwner());

}

void UFPSPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!Owner)
	{
		return;
	}

	LocomotionState = Owner->GetLocomotionState();
	ActionState = Owner->GetActionState();
}
