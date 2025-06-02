// FPSShooter


#include "Characters/Player/FPSPlayerAnimInstance.h"
#include "Characters/Player/FPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFPSPlayerAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AFPSPlayer>(TryGetPawnOwner());

}

void UFPSPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter)
	{
		return;
	}

	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();
	LocomotionState = OwnerCharacter->GetLocomotionState();
	ActionState = OwnerCharacter->GetActionState();
}
