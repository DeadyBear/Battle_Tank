// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFirngStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_BATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UTankAimingComponent();

	void AimingTowards(FVector , float);

	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimDirection);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitialiseAimingComponents(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);


private:
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly , Category = "State")
	EFirngStatus FiringStatus = EFirngStatus::Aiming;
};
