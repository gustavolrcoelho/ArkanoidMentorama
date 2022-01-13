// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class ARKANOIDMENTORAMA_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector LaunchDirection = FVector(1, 0, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float LaunchSpeed = 500;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentSpeed;

	const float Tolerance = 0.1f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Launch();

	void PrintDebug() { 
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Orange, TEXT("PrintDebug from inside Ball"));
	}

};
