// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//codigo que indica que control esta asignado a cada tanque
	/*auto ControlledTank = GetAITankController();
	if (!ControlledTank)
		{
			UE_LOG(LogTemp,Warning,TEXT("AI Controller not possesing a Tank"))
		}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing: %s"), *ControlledTank->GetName())
	}
*/
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find Player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found Player Tank: %s"), *PlayerTank->GetName())
	}

}

ATank* ATankAIController::GetAITankController() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	//return Cast<ATank>(PlayerTank);
	return Cast<ATank>(PlayerTank);
}



