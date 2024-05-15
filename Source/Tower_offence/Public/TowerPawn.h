// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurrentPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "TowerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OFFENCE_API ATowerPawn : public ATurrentPawn
{
	GENERATED_BODY()
	

public:

	ATowerPawn();

	UFUNCTION(BlueprintCallable, Category = "Moving")
	void Turn(FVector TargetLocation);


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inputs")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Moving")
	void AI_PlayerShooting(FVector TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Instrument")
	bool TowerCheck();

protected:

public:


};

static int CountOfTowers = 0;