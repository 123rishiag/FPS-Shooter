// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSPlayer.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;

UCLASS()
class FPSSHOOTER_API AFPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSPlayer();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* ArmsMesh;
};
