// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::NotifyHit( class UPrimitiveComponent* MyComp,
						AActor* Other,
						class UPrimitiveComponent* OtherComp,
						bool bSelfMoved,
						FVector HitLocation,
						FVector HitNormal,
						FVector NormalImpulse,
						const FHitResult& Hit) {

	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("I'VE BEEN HIT!"));

	FeedbackDestroy();

	if (TimeToFeedBackDestroy > 0)
	{
		SetLifeSpan(TimeToFeedBackDestroy);
	}
	else
	{
		Destroy();
	}

}

//void ABrick::DestroyFeedback_Implementation()
//{
//
//}

