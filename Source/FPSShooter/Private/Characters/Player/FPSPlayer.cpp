// FPSShooter


#include "Characters/Player/FPSPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

AFPSPlayer::AFPSPlayer()
{
 	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Arms"));
	ArmsMesh->SetupAttachment(Camera);
}

void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

