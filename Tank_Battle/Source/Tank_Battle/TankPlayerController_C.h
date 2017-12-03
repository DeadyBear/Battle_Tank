// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_C.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class TANK_BATTLE_API ATankPlayerController_C : public APlayerController
{
	GENERATED_BODY()
		virtual void Tick(float DeltaTime) override;

		void BeginPlay() override;

		ATank* GetTankController() const;
	
		void AimTowardsCrosshair();
	
		bool GetSightRayHitLocation(FVector &) const;

		UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;

		UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.333f;

		UPROPERTY(EditDefaultsOnly)
		float Range = 1000000.0f;

		bool GetCameraLookDirection(FVector2D  , FVector &) const;

		bool GetLookVectorHitLocation(FVector &, FVector&) const;
};
