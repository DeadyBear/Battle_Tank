// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Classes/Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretRefrence(UTankTurret *TurretToSet)
{
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	//...
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimingTowards(FVector Hitlocation , float LaunchSpeed)
{
	if (!Barrel) { UE_LOG(LogTemp, Error, TEXT("Barrel Not Found!!")); }
	if (!Turret) { UE_LOG(LogTemp, Error, TEXT("Turret Not Found!!")); }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSoulutuin = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, Hitlocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSoulutuin)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim Solution found"), time);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();

	FRotator DeltaRotaion = AimAsRotator - BarrelRotation;

	Barrel->Elevate(DeltaRotaion.Pitch);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	FRotator TurretRotation = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	
	FRotator DeltaRotaion = AimAsRotator - TurretRotation;

	Turret->Rotate(DeltaRotaion.Yaw);
}
