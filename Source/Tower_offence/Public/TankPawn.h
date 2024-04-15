// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurrentPawn.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "TankPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OFFENCE_API ATankPawn : public ATurrentPawn
{
	GENERATED_BODY()
	
public:

	ATankPawn();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void Move(float DistansToMove);

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void Turn(float Rotation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inputs")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Inputs")
	void TurrentRotation();

protected:

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	TObjectPtr<UCameraComponent> Camera;
};
