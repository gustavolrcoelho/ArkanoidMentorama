// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ArkanoidPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()

	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly)
	FName HorizontalInputAxis = TEXT("Horizontal");

public:
	UFUNCTION(BlueprintCallable)
	void HandleHorizontalAxis(float Value);
};
