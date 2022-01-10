// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball.h"
#include "ArkanoidPlayerController.generated.h"

/**
 * 
 */

class Aball;

UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:	
	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName HorizontalInputAxis = TEXT("Horizontal");

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName LaunchInput = TEXT("Launch");

	ABall* HoldingBall;

	UPROPERTY(EditAnywhere, Category = "Ball");
	FVector OffsetSpawnInitialBall = FVector(0, 0, 40);
	
	UPROPERTY(EditAnywhere, Category = "Ball");
	TSubclassOf<ABall> BallClass;

	UFUNCTION(BlueprintCallable)
	void HandleHorizontalAxis(float Value);

	UFUNCTION(BlueprintCallable)
	void StartInitialState();

	UFUNCTION(BlueprintCallable)
	void HandleLaunch();

	UFUNCTION(BlueprintCallable)
	ABall* SpawnBall();

	UFUNCTION(BlueprintCallable)
	void HandleDestroyedBall();
};
