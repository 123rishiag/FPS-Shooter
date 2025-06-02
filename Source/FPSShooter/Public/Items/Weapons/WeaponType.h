// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "WeaponType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    EWT_Rifle UMETA(DisplayName = "Rifle"),
};
