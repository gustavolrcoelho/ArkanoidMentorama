// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBallDestroyed, class ABall*, Ball);

UCLASS()
class ARKANOIDMENTORAMA_API ABall : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	FOnBallDestroyed OnBallDestroyed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector LaunchDirection = FVector(1, 0, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float LaunchSpeed = 500;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentSpeed;

	const float Tolerance = 0.1f;
	
	// Sets default values for this actor's properties
	ABall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintCallable)
	void Launch();

	void Kill();
};
