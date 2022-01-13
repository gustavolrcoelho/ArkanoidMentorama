// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickManager.h"

// Sets default values for this component's properties
UBrickManager::UBrickManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UBrickManager::BeginPlay()
{
	Super::BeginPlay();
}

//// Called every frame
//void UBrickManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UBrickManager::SpawnBricks()
{
	for (int Rows = 0; Rows < NumRows; Rows++)
	{
		for (int Colums = 0; Colums < NumCols; Colums++)
		{
			auto* Brick = GetWorld()->SpawnActor<ABrick>(BrickClass.Get());

			if (BrickExtend.IsZero())
			{
				FVector Origin;// = { 0, 0, 0 };

				Brick->GetActorBounds(true, Origin, BrickExtend);
			}

			Brick->SetActorLocation(GetPositionFor(Rows, Colums));
		}
	}
}

FVector UBrickManager::GetPositionFor(int X, int Z)
{
	FVector Position = StartSpawnPosition;
	//GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Orange, FString::Printf(TEXT("called GetPositionFor(%d, %d)"), X, Z));

	Position.X += X * BrickExtend.X * 2;
	Position.X += X * OffsetBetweenBricks.X;

	Position.Z -= Z * BrickExtend.Z * 2;
	Position.Z -= Z * OffsetBetweenBricks.Z;

	return Position;
}

