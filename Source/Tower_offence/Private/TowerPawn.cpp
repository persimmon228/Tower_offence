// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"

void ATowerPawn::Turn(float Rotation)
{
	FRotator NewRotation = MyTurretMesh->GetComponentRotation() + FRotator(0.0f, Rotation, 0.0f);
	MyTurretMesh->SetWorldRotation(NewRotation);
}
