// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Public/BrickManager.h"
#include "Public/ArkanoidPlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidMentoramaGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartRound, int, Round);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameOver, int, Score);

UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidMentoramaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	AArkanoidMentoramaGameModeBase();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float TimeToStartRound = .5f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float TimeToRestartAfterDeath = .5f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UBrickManager* BrickManager;

	UPROPERTY(BlueprintAssignable)
	FOnStartRound OnStartRound;

	UPROPERTY(BlueprintAssignable)
	FOnGameOver OnGameOver;

	int CurrentRound = 0;

	UFUNCTION()
	void OnAllBricksDestroyed();

	UFUNCTION()
	void OnAllBallsDestroyed();

	void StartRound(int Round);
};
