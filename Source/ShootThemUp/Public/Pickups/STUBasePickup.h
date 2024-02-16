// Shoot Them Up Game. All Rights Resrved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBasePickup : public AActor
{
    GENERATED_BODY()

public:
    ASTUBasePickup();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    float RespawnTime = 5.0f;

    UPROPERTY()
    TArray<APawn*> OverlappingPawns;

    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

public:
    virtual void Tick(float DeltaTime) override;
    bool CouldBeTaken() const;

private:
    float RotationYaw = 0.0f;

    virtual bool GivePickupTo(APawn* PlayerPawn);
    FTimerHandle RespawnTimerHandle;

    void PickupWasTaken();
    void Respawn();
    void GenerateRotationYaw();
};
