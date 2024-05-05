// Shoot Them Up Game. All Rights Resrved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUGameInstance.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
    GENERATED_BODY()

    public:
    FName GetStartupLevelName() const { return StartupLevelName; }

    protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
        FName StartupLevelName = NAME_None;
};
