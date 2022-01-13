// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	RootComponent = Sphere;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector Velocity = GetVelocity();

	if (CurrentSpeed >= 0) return;
	if (Velocity.IsNearlyZero()) return;

	if (FMath::IsNearlyZero(Velocity.X, Tolerance))
	{
		Velocity.X += Tolerance * FMath::RandBool() ? 1 : -1;
	}
		
	if (FMath::IsNearlyZero(Velocity.Z, Tolerance))
	{
		Velocity.Z += Tolerance * FMath::RandBool() ? 1 : -1;
	}

	Velocity.Normalize();
	Velocity *= CurrentSpeed;

	Sphere->SetPhysicsLinearVelocity(Velocity, false, NAME_None);

}

void ABall::Launch()
{
	Sphere->AddImpulse(LaunchDirection.GetSafeNormal() * LaunchSpeed, NAME_None, true);
	CurrentSpeed = LaunchSpeed;
}

