// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurrentPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inputs")
	void Move(float DistansToMove);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inputs")
	void Turn(float Rotation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inputs")
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	TObjectPtr<UCameraComponent> Camera;
};
