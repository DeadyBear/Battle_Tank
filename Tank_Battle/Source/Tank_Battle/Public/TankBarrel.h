// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, Category= Setup)
	float MaxElvation = 30;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElvation = 0;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSeconds =5 ;

public:
	void Elevate(float Relativespeed);
};
