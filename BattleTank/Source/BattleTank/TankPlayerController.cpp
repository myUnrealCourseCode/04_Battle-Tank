// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if (!controlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}

	else if (controlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("PlayController possessing %s"), *(controlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter

	if (GetSightRayHitLocation(HitLocation)) {

		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
}

// get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const{

	// Find the crosshair position
	FVector worldDirection;
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	// De-projext the screen position of the croshair to a world direction
	if (GetLookDirection(ScreenLocation,worldDirection)) {

		UE_LOG(LogTemp, Warning, TEXT("Look direction is: %s"), *worldDirection.ToString());
	}
	// line trace along that look direction, and see what we hit (up to mac range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {

	FVector cameraWorldLocation; // to be discarded

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.X, 
		cameraWorldLocation, 
		LookDirection); 
	
}