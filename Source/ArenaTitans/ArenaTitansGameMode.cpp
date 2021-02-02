// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArenaTitansGameMode.h"
#include "ArenaTitansHUD.h"
#include "ArenaTitansPlayerController.h"
#include "ArenaTitansCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArenaTitansGameMode::AArenaTitansGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AArenaTitansPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> HUDBPClass(TEXT("/Game/TopDownCPP/HUD"));
	if (HUDBPClass.Class != nullptr)
	{
		HUDClass = HUDBPClass.Class;
	}
}