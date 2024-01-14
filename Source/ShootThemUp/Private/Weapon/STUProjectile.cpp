// Shoot Them Up Game. All Rights Resrved.

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

ASTUProjectile::ASTUProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionCpomponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionCpomponent->InitSphereRadius(5.0f);
    CollisionCpomponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionCpomponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    SetRootComponent(CollisionCpomponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 0.0f;
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();

    check(MovementComponent);
    check(CollisionCpomponent);

    MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
    CollisionCpomponent->IgnoreActorWhenMoving(GetOwner(), true);
    CollisionCpomponent->OnComponentHit.AddDynamic(this, &ASTUProjectile::OnProjectileHit);
    SetLifeSpan(LifeSeconds);
}

void ASTUProjectile::OnProjectileHit(
    UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!GetWorld()) return;

    MovementComponent->StopMovementImmediately();

    // make damage
    UGameplayStatics::ApplyRadialDamage(GetWorld(),  //
        DamageAmount,                                //
        GetActorLocation(),                          //
        DamageRadius,                                //
        UDamageType::StaticClass(),                  //
        {GetOwner()},                                //
        this,                                        //
        GetController(),                             //
        DoFullDamage);

    DrawDebugSphere(GetWorld(), GetActorLocation(), DamageRadius, 24, FColor::Red, false, 5.0f);

    Destroy();
}

AController* ASTUProjectile::GetController() const {
    const auto Pawn = Cast<APawn>(GetOwner());
    return Pawn ? Pawn->GetController() : nullptr;
}
