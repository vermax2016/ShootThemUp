// Shoot Them Up Game. All Rights Resrved.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const 
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    // проверяем бежит персонаж или нет, если да то изменяем MaxSpeed
    // если услове неверно, возвращаем MaxSpeed
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed; 
}