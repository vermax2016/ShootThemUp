// Shoot Them Up Game. All Rights Resrved.

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"

ASTUProjectile::ASTUProjectile()
{

    PrimaryActorTick.bCanEverTick = false;

    CollisionCpomponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionCpomponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionCpomponent);
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();
}
