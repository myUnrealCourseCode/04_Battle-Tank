// Fill out your copyright notice in the Description page of Project Settings.

#include "./Public/Tank.h"
#include "./Public/TankAimingComponent.h"
#include "Engine/World.h"


void ATank::SetBarrelReference(UTankBarrel * BarrelToSet) {

	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet) {

	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire() {

	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : tank has fired"), Time);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// no need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation) {

	TankAimingComponent->AimAt(OutHitLocation , LaunchSpeed);
}