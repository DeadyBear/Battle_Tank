// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	FString TankAIController = GetTankAIController()->GetName();
	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerTank was not found"));
		return;
	}
	FString PlayerTank = GetPlayerTank()->GetName();
	if (!GetTankAIController())
	{
		UE_LOG(LogTemp, Error, TEXT("TankController is not possesed"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI possesed by : %s"), *TankAIController);
	}



	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerTank was not found"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found  : %s"), *TankAIController , *PlayerTank);
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector HitLocation = GetPlayerTank()->GetActorLocation();

	GetTankAIController()->AimAt(HitLocation);

}

ATank * ATankAIController::GetTankAIController() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}