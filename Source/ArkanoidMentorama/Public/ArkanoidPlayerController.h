// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball.h"
#include "ArkanoidPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName HorizontalInputAxis = TEXT("Horizontal");

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName LaunchInput = TEXT("Launch");

	ABall *HoldingBall;

	UPROPERTY(EditAnywhere, Category = "Ball");
	FVector OffsetSpawnInitialBall = FVector(0, 0, 40);
	
	UPROPERTY(EditAnywhere, Category = "Ball");
	TSubclassOf<ABall> BallClass;

public:
	UFUNCTION(BlueprintCallable)
	void HandleHorizontalAxis(float Value);

	UFUNCTION(BlueprintCallable)
	void StartInitialStage();

	UFUNCTION(BlueprintCallable)
	void HandleLaunch();

	UFUNCTION(BlueprintCallable)
	ABall *SpawnBall();

	UFUNCTION(BlueprintCallable)
	void HandleDestroyedBall();
};
