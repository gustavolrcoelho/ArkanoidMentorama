// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ball.h"
#include "ArkanoidPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllBallsDestroyed);

class Aball;

UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY()
	ABall* HoldingBall;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	TArray<ABall*> Balls;

public:	
	void SetupInputComponent();

	FOnAllBallsDestroyed OnAllBallsDestroyed;

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName HorizontalInputAxis = TEXT("Horizontal");

	UPROPERTY(EditDefaultsOnly, Category = Input);
	FName LaunchInput = TEXT("Launch");

	UPROPERTY(EditAnywhere, Category = "Ball");
	FVector OffsetSpawnInitialBall = FVector(0, 0, 40);
	
	UPROPERTY(EditAnywhere, Category = "Ball");
	TSubclassOf<ABall> BallClass;

	UFUNCTION()
	void HandleHorizontalAxis(float Value);

	void StartInitialState();

	void HandleLaunch();

	ABall* SpawnBall();

	UFUNCTION()
	void OnBallDestroyed(ABall* Ball);

	void DestroyAllBalls();
};
