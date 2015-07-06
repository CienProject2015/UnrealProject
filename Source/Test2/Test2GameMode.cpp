// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Test2.h"
#include "Test2GameMode.h"
#include "Test2Character.h"

ATest2GameMode::ATest2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScroller/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
