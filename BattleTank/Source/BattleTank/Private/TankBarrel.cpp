// Fill out your copyright notice in the Description page of Project Settings.

#include "./Public/TankBarrel.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


void UTankBarrel::Elevate(float RelativeSpeed) {

	// Move the barrel the right amount this frame

	// Given a max elevation speed and teh frame time

	RelativeSpeed = FMath::Clamp<float> (RelativeSpeed, -1, +1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp <float> (RawNewElevation, MinElevatonDegrees, MaxElevatonDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}