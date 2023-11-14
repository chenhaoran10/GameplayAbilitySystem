// Copyright Epic Games, Inc. All Rights Reserved.

#include "LGGameMode.h"
#include "LGCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALGGameMode::ALGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
