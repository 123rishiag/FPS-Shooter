// FPSShooter


#include "Characters/Player/FPSPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AFPSPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
        {
            for (int32 i = 0; i < InputMappingContexts.Num(); ++i)
            {
                if (InputMappingContexts[i])
                {
                    Subsystem->AddMappingContext(InputMappingContexts[i], i);
                }
            }
        }
    }
}