// Fill out your copyright notice in the Description page of Project Settings.

#include "./Public/TankAIController.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	ATank* playerTank = GetPlayerTank();

	if (!playerTank) {

		UE_LOG(LogTemp, Warning, TEXT("AIController is not possessing a Tank"));

	}

	else {

		UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *playerTank->GetName());
	}
	//auto controlledTank = GetControlledTank();
}

ATank * ATankAIController::GetControlledTank() const{

	return Cast <ATank> (GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const {

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);

}
