// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidMentoramaGameModeBase.h"

AArkanoidMentoramaGameModeBase::AArkanoidMentoramaGameModeBase() : Super()
{
	BrickManager = CreateDefaultSubobject<UBrickManager>(TEXT("BrickManager"));
}

void AArkanoidMentoramaGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	BrickManager->SpawnBricks();
}