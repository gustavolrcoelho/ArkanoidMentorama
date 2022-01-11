// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Public/BrickManager.h"
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
	AArkanoidMentoramaGameModeBase();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBrickManager* BrickManager;
};
