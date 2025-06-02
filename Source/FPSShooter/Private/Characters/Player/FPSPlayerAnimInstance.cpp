// FPSShooter


#include "Characters/Player/FPSPlayerAnimInstance.h"
#include "Characters/Player/FPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFPSPlayerAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AFPSPlayer>(TryGetPawnOwner());
	if (OwnerCharacter)
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}

}

void UFPSPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter || !OwnerMovementComponent)
	{
		return;
	}

	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
