// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"

void ATowerPawn::Turn(float Rotation)
{
	FRotator NewRotation = MyTurretMesh->GetComponentRotation() + FRotator(0.0f, Rotation, 0.0f);
	MyTurretMesh->SetWorldRotation(NewRotation);
}


void ATowerPawn::Fire()
{
	GetWorld()->SpawnActor<AProjectileBase>(MyProjectileSpawnPoint->GetComponentLocation(), MyProjectileSpawnPoint->GetComponentRotation());
}

void ATowerPawn::AI_PlayerShooting(FVector TargetLocation)
{
	FVector MeshLocation = MyTurretMesh->GetComponentLocation();
	FVector PawnLocation = TargetLocation;

	FRotator TurretRotation = UKismetMathLibrary::FindLookAtRotation(PawnLocation, MeshLocation);

    // Set the turret's relative rotation to face the player pawn
    MyTurretMesh->AddLocalRotation(TurretRotation);

    // Fire at the player pawn
    Fire();
}
void ATowerPawn::Tick(float DeltaTime)
{

}