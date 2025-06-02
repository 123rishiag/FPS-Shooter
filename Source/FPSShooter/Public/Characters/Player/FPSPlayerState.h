// FPSShooter

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EFPSPlayerLocomotionState : uint8
{
    EFPSPLS_Idle UMETA(DisplayName = "Idle"),
    EFPSPLS_Walk UMETA(DisplayName = "Walk"),
    EFPSPLS_Sprint UMETA(DisplayName = "Sprint"),
    EFPSPLS_Jump UMETA(DisplayName = "Jump"),
};

UENUM(BlueprintType)
enum class EFPSPlayerActionState : uint8
{
    EFPSPAS_None UMETA(DisplayName = "None"),
    EFPSPAS_Aim UMETA(DisplayName = "Aim"),
    EFPSPAS_Shoot UMETA(DisplayName = "Shoot"),
    EFPSPAS_AimShoot UMETA(DisplayName = "Aim Shoot"),
};