                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"

void AArkanoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(HorizontalInputAxis, this, &AArkanoidPlayerController::HandleHorizontalAxis);
	InputComponent->BindAction(LaunchInput, IE_Pressed, this, &AArkanoidPlayerController::HandleLaunch);
}

void AArkanoidPlayerController::HandleHorizontalAxis(float Value)
{
	if (!IsValid(GetPawn())) return;

	GetPawn()->AddMovementInput(FVector::ForwardVector, Value);
}

void AArkanoidPlayerController::StartInitialStage()
{
	HoldingBall = SpawnBall();
	HoldingBall->SetActorLocation(GetPawn()->GetActorLocation() + OffsetSpawnInitialBall);
}

void AArkanoidPlayerController::HandleLaunch()
{
}

ABall* AArkanoidPlayerController::SpawnBall()
{
	auto *Ball = GetWorld()->SpawnActor<ABall>(BallClass.Get());
	
	//minuto 16:23 da aula 4
}

void AArkanoidPlayerController::HandleDestroyedBall()
{
}
                            