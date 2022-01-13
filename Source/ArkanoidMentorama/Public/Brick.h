// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBrickDestroyed, ABrick*, Brick);

UCLASS()
class ARKANOIDMENTORAMA_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	float TimeToFeedBackDestroy;

	UPROPERTY(BlueprintAssignable)
	FOnBrickDestroyed OnBrickDestroyed;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit( class UPrimitiveComponent* MyComp,
							AActor* Other,
							class UPrimitiveComponent* OtherComp,
							bool bSelfMoved,
							FVector HitLocation,
							FVector HitNormal,
							FVector NormalImpulse,
							const FHitResult& Hit) override;

	UFUNCTION(BlueprintImplementableEvent)
	void FeedbackDestroy();

	int GetScoreValue() const;
};
