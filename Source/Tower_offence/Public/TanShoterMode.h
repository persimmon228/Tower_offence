// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TanShoterMode.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OFFENCE_API ATanShoterMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(Exec, BlueprintImplementableEvent, Category = "Comands")
	int32 ChangeColor(int32 color, int32 Tank);
};
