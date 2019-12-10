// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnrealExercisesGameMode.h"
#include "UnrealExercisesHUD.h"
#include "UnrealExercisesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealExercisesGameMode::AUnrealExercisesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealExercisesHUD::StaticClass();
}
