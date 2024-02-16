// Shoot Them Up Game. All Rights Resrved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_PickupCouldBeTaken.generated.h"

UCLASS()
class SHOOTTHEMUP_API UEnvQueryTest_PickupCouldBeTaken : public UEnvQueryTest
{
    GENERATED_BODY()

public:
    UEnvQueryTest_PickupCouldBeTaken(const FObjectInitializer& FObjectInitializer);
    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
};
