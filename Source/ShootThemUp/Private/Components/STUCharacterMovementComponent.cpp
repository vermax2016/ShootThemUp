// Shoot Them Up Game. All Rights Resrved.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const 
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    // check if the character is running or not, if so, change maxSpeed
    // if the condition is incorrect, return maxSpeed
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed; 
}