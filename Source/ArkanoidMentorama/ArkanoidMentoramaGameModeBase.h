// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidMentoramaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidMentoramaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
};
