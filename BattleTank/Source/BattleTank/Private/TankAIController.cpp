// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetAITankController();
	if (!ControlledTank)
		{
			UE_LOG(LogTemp,Warning,TEXT("AI Controller not possesing a Tank"))
		}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing: %s"), *GetAITankController()->GetName())
	}

}
ATank* ATankAIController::GetAITankController()
{
	return Cast<ATank>(GetPawn());
}



