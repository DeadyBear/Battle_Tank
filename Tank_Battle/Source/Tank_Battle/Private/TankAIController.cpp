// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	ATank* PlayerTank  = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AITank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		FVector Hitlocation = PlayerTank->GetActorLocation();
		AITank->AimAt(Hitlocation);
		AITank->fire();
	}
}