// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidMentoramaGameModeBase.h"

AArkanoidMentoramaGameModeBase::AArkanoidMentoramaGameModeBase() : Super()
{
	BrickManager = CreateDefaultSubobject<UBrickManager>(TEXT("BrickManager"));
	BrickManager->OnAllBricksDestroyed.AddDynamic(this, &AArkanoidMentoramaGameModeBase::OnAllBricksDestroyed);
}

void AArkanoidMentoramaGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//BrickManager->SpawnBricks();
	StartRound(CurrentRound);

	//auto* PlayerController = GetWorld()->GetFirstPlayerController();
	//auto* ArkanoidPlayerController = Cast<AArkanoidPlayerController>(PlayerController);
	//
	//if (IsValid(ArkanoidPlayerController))
	//{
	//	ArkanoidPlayerController->OnAllBallsDestroyed.AddDynamic(this, &AArkanoidMentoramaGameModeBase::OnAllBallsDestroyed);
	//}
	auto* PlayerController = Cast<AArkanoidPlayerController>(GetWorld()->GetFirstPlayerController());
	check(PlayerController);
	PlayerController->OnAllBallsDestroyed.AddDynamic(this, &AArkanoidMentoramaGameModeBase::OnAllBallsDestroyed);
}

void AArkanoidMentoramaGameModeBase::StartRound(int Round)
{
	auto* PlayerController = Cast<AArkanoidPlayerController>(GetWorld()->GetFirstPlayerController());
	check(PlayerController);

	OnStartRound.Broadcast(Round);

	if (Round <= 0)
	{
		BrickManager->SpawnBricks();
		PlayerController->StartInitialState();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Round is %d"), Round));
	}
	else
	{
		//CurrentRound = Round;
		PlayerController->UnPossess();
		PlayerController->DestroyAllBalls();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Round is %d"), Round));

		FTimerHandle TimerHandle;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, PlayerController]()
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Inside lambda"));
				BrickManager->SpawnBricks();

				RestartPlayer(PlayerController);
				PlayerController->StartInitialState();

			}, TimeToStartRound, false);
	}
}

void AArkanoidMentoramaGameModeBase::OnAllBricksDestroyed()
{
	StartRound(CurrentRound++);
}

void AArkanoidMentoramaGameModeBase::OnAllBallsDestroyed()
{
	FTimerHandle Handle;

	GetWorld()->GetTimerManager().SetTimer(Handle, [this]()
		{
			auto* PlayerController = Cast<AArkanoidPlayerController>(GetWorld()->GetFirstPlayerController());
			check(PlayerController);
			auto* PlayerState = PlayerController->GetPlayerState<AArkanoidPlayerState>();

			PlayerState->Life--;

			if (PlayerState->Life > 0)
			{
				RestartPlayer(PlayerController);
				PlayerController->StartInitialState();
			}
			else
			{
				OnGameOver.Broadcast(PlayerState->GetScore());
			}
		}, TimeToRestartAfterDeath, false);
}
