// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void IntendMove(float Throw);

	UFUNCTION(BlueprintCallable)
	void IntendTurn(float Throw);

	UFUNCTION(BlueprintCallable)
	void Intialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
