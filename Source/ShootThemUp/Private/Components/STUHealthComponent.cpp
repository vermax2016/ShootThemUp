// Shoot Them Up Game. All Rights Resrved.

#include "Components/STUHealthComponent.h"

USTUHealthComponent::USTUHealthComponent()
{

    PrimaryComponentTick.bCanEverTick = false;
}

void USTUHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
}