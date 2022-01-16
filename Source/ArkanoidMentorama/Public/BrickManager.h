// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Brick.h"
#include "ArkanoidPlayerState.h"
#include "Components/ActorComponent.h"
#include "BrickManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOIDMENTORAMA_API UBrickManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBrickManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly, Category = "Brick");
	TSubclassOf<ABrick> BrickClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Brick");
	int NumRows = 4;
	
	UPROPERTY(EditDefaultsOnly, Category = "Brick");
	int NumCols = 9;

	FVector BrickExtend;

	UPROPERTY(EditAnywhere, Category = "Brick");
	FVector StartSpawnPosition;

	UPROPERTY(EditAnywhere, Category = "Brick");
	FVector OffsetBetweenBricks;

	//	// Called every frame
	//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SpawnBricks();

	FVector GetPositionFor(int X, int Z);

	UFUNCTION(BlueprintCallable)
	void HandleBrickDestroyed(ABrick *DestroyedBrick);
};
