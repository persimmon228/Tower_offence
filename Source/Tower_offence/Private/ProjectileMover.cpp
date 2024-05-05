// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileMover.h"

// Sets default values for this component's properties
UProjectileMover::UProjectileMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOwner()->SetActorLocation((GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 10.0f)));
}

