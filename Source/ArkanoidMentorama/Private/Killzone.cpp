// Fill out your copyright notice in the Description page of Project Settings.


#include "Killzone.h"

// Sets default values
AKillzone::AKillzone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKillzone::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AKillzone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKillzone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	auto* Ball = Cast<ABall>(OtherActor);
	
	if (IsValid(Ball))
	{
		Ball->Kill();
	}
}