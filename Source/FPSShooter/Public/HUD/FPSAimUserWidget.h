// FPSShooter

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPSAimUserWidget.generated.h"

class UBorder;

/**
 * 
 */
UCLASS()
class FPSSHOOTER_API UFPSAimUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UBorder* CenterBorder;

    UPROPERTY(meta = (BindWidget))
    UBorder* LeftBorder;

    UPROPERTY(meta = (BindWidget))
    UBorder* RightBorder;
};
