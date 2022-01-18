// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ArkanoidPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDMENTORAMA_API AArkanoidPlayerState : public APlayerState
{
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int Life;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int IntialLife = 3;
};
