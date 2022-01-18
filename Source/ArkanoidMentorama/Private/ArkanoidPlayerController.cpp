                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"

void AArkanoidPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//StartInitialState();
}

void AArkanoidPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (IsValid(HoldingBall) && IsValid(GetPawn()))
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
	else
	{
		FVector Offset( 0.f, -300.f, 0.f );
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Offset Y is %f"), Offset.Y));
		HoldingBall->SetActorLocation(Offset);
	}
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

ABall* AArkanoidPlayerController::SpawnBall()
{
	auto* Ball = GetWorld()->SpawnActor<ABall>(BallClass.Get());
	
	Balls.Add(Ball);
	Ball->OnBallDestroyed.AddDynamic(this, &AArkanoidPlayerController::OnBallDestroyed);

	return Ball;
}

void AArkanoidPlayerController::OnBallDestroyed(ABall* Ball)
{
	Balls.Remove(Ball);
	if (Balls.Num() <= 0)
	{
		UnPossess();
		OnAllBallsDestroyed.Broadcast();
	}
}

void AArkanoidPlayerController::DestroyAllBalls()
{
	for (auto* Ball : Balls)
	{
		Ball->Destroy();
	}
	Balls.Reset();
}