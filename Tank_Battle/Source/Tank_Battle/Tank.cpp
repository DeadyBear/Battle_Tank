// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"
#include "Framework/Application/SlateApplication.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector &Hitlocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimingTowards(Hitlocation, LaunchSpeed);
}


void ATank::fire()
{
	bool IsReloadTime = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTime;
	if (Barrel && IsReloadTime)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastTimeFire = FPlatformTime::Seconds();
	}
}