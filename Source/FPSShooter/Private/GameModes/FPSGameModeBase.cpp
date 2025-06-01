// FPSShooter


#include "GameModes/FPSGameModeBase.h"
#include "Characters/Player/FPSPlayer.h"
#include "Characters/Player/FPSPlayerController.h"

AFPSGameModeBase::AFPSGameModeBase()
{
    DefaultPawnClass = AFPSPlayer::StaticClass();
    PlayerControllerClass = AFPSPlayerController::StaticClass();
}