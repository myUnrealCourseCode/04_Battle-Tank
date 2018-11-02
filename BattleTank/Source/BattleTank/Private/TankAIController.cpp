// Fill out your copyright notice in the Description page of Project Settings.

#include "./Public/TankAIController.h"
#include "./Public/Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

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

void ATankAIController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {

		// TODO move towards the player 

		// Aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
	}
}

ATank * ATankAIController::GetControlledTank() const{

	return Cast <ATank> (GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const {

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);

}
