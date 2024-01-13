// Shoot Them Up Game. All Rights Resrved.

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


ASTUProjectile::ASTUProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionCpomponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionCpomponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionCpomponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 0.0f;
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();

    check(MovementComponent);
    MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
    SetLifeSpan(5.0f);
}
