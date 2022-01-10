                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"

void AArkanoidPlayerController::BeginPlay()
{
	Super::BeginPlay();

	StartInitialState();
}

void AArkanoidPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (IsValid(HoldingBall))
	{
		HoldingBall->SetActorLocation(GetPawn()->GetActorLocation() + OffsetSpawnInitialBall);
	}
}

void AArkanoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(HorizontalInputAxis, this, &AArkanoidPlayerController::HandleHorizontalAxis);
	InputComponent->BindAction(LaunchInput, IE_Pressed, this, &AArkanoidPlayerController::HandleLaunch);
}

void AArkanoidPlayerController::StartInitialState()
{
	HoldingBall = SpawnBall();
	
	if (IsValid(HoldingBall) && IsValid(GetPawn()))
	{
		HoldingBall->SetActorLocation(GetPawn()->GetActorLocation() + OffsetSpawnInitialBall);
	}
}

ABall* AArkanoidPlayerController::SpawnBall()
{
	auto *Ball = GetWorld()->SpawnActor<ABall>(BallClass.Get());

	return Ball;
}

void AArkanoidPlayerController::HandleHorizontalAxis(float Value)
{
	if (!IsValid(GetPawn())) return;

	GetPawn()->AddMovementInput(FVector::ForwardVector, Value);
}

void AArkanoidPlayerController::HandleLaunch() 
{
	if (IsValid(HoldingBall))
	{
		HoldingBall->Launch();
		HoldingBall = nullptr;
	}
}

void AArkanoidPlayerController::HandleDestroyedBall()
{
}