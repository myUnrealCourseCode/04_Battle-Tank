// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if (!controlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}

	else if (controlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("PlayController possessing %s"), *(controlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}
