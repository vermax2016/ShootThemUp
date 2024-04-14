// Shoot Them Up Game. All Rights Resrved.

#include "Menu/STUMenuGameModeBase.h"
#include "Menu/STUMenuPlayerController.h"
#include "Menu/UI/STUMenuHUD.h"

ASTUMenuGameModeBase::ASTUMenuGameModeBase() 
{
    PlayerControllerClass = ASTUMenuPlayerController::StaticClass();
    HUDClass = ASTUMenuHUD::StaticClass();
}
