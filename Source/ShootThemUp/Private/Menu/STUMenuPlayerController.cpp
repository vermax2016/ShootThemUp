// Shoot Them Up Game. All Rights Resrved.

#include "Menu/STUMenuPlayerController.h"

void ASTUMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
