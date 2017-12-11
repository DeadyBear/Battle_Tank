// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController_C.h"
#include "Public/Math/Color.h"
#include "Public/DrawDebugHelpers.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankPlayerController_C::BeginPlay()
{	
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Donkey:TankPlayerController BeginPlay() Called"));

	if (!GetTankController())
	{
		UE_LOG(LogTemp, Error, TEXT("TankController is not possesed"));
		return;
	}
}

ATank * ATankPlayerController_C::GetTankController() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController_C::AimTowardsCrosshair()
{
	if(!GetTankController()) {return;}
	FVector Hitlocation;

	if(GetSightRayHitLocation(Hitlocation))
	{
		GetTankController()->AimAt(Hitlocation);
	}
}

bool ATankPlayerController_C::GetSightRayHitLocation(FVector  &outHitlocation) const
{
	int32 VeiwportSizeX, VeiwportSizeY;
	GetViewportSize(VeiwportSizeX, VeiwportSizeY);
	
	FVector2D ScreenLocation(VeiwportSizeX*CrosshairXLocation, VeiwportSizeY*CrosshairYLocation);

	FVector CameralookDirection;
	if (GetCameraLookDirection(ScreenLocation, CameralookDirection))
	{
		if (GetLookVectorHitLocation(CameralookDirection, outHitlocation))
			return true;
	}

	return false;
}

bool ATankPlayerController_C::GetCameraLookDirection(FVector2D ScreenLocation, FVector &CameralookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, CameralookDirection);
}

bool ATankPlayerController_C::GetLookVectorHitLocation(FVector &CameralookDirection , FVector &Hitlocation) const
{
	FHitResult Hit;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceRange = StartLocation + CameralookDirection * Range;

	if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, LineTraceRange, ECollisionChannel::ECC_Visibility))
	{
		Hitlocation = Hit.Location;
		return true;
	}
	else
	{
		Hitlocation = FVector(0);
		return false;
	}
}
