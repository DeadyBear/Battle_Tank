// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RawRelativespeed)
{
	auto Relativespeed = FMath::Clamp<float>(RawRelativespeed , -1, 1);
	auto ElevationChange = Relativespeed * MaxDegreesPerSeconds *  GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto NewElevation = FMath::Clamp<float>(RawNewElevation, MinElvation, MaxElvation);
	
	SetRelativeRotation(FRotator(NewElevation,0,0));
}
