// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 5;

public:
	void Rotate(float RelativeSpeed);
	

};
