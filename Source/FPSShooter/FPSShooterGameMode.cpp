// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSShooterGameMode.h"
#include "FPSShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSShooterGameMode::AFPSShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
