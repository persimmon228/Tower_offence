// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurrentPawn.h"
#include "TowerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OFFENCE_API ATowerPawn : public ATurrentPawn
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable, Category = "Moving")
	void Turn(float Rotation);
};
