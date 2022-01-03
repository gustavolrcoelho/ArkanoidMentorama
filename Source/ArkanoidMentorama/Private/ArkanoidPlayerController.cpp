// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"

void AArkanoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(HorizontalInputAxis, this, &AArkanoidPlayerController::HandleHorizontalAxis);
}

void AArkanoidPlayerController::HandleHorizontalAxis(float Value)
{
	if (!IsValid(GetPawn())) return;

	GetPawn()->AddMovementInput(FVector::ForwardVector, Value);
}
