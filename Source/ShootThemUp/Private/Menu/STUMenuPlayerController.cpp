// Shoot Them Up Game. All Rights Resrved.

#include "Menu/STUMenuPlayerController.h"
#include "STUGameInstance.h"

void ASTUMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;

    GetWorld()->GetGameInstance<USTUGameInstance>()->TestString = "Menu level says Hello";
}
