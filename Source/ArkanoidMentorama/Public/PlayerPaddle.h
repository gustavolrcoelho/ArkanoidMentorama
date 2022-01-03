// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class ARKANOIDMENTORAMA_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	// Sets default values for this pawn's properties
	APlayerPaddle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

};
