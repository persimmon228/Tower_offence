// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPawn.h"

void ATowerPawn::Turn(FVector TargetLocation)
{
	FRotator TargetRotation{ (TargetLocation - GetActorLocation()).Rotation() };
	TargetRotation.Yaw -= 90;

	const FRotator TurretRotationInterpolation = FMath::RInterpConstantTo(MyTurretMesh->GetComponentRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 150.f);

	const FRotator TurretNewRotation = { 0, TurretRotationInterpolation.Yaw, 0 };

	MyTurretMesh->SetWorldRotation(TurretNewRotation);
}


//void ATowerPawn::Fire()
//{
//	FActorSpawnParameters SpawnParams;
//	SpawnParams.Owner = this;
//	SpawnParams.Instigator = GetInstigator();
//
//	UBP_Projectile* Projectile = GetWorld()->SpawnActor<UBP_Projectile>(ProjectileBase, MyProjectileSpawnPoint->GetComponentLocation(), MyProjectileSpawnPoint->GetComponentRotation(), SpawnParams);
//
//	if (Projectile)
//	{
//		FVector LaunchDirection = MyProjectileSpawnPoint->GetComponentLocation();
//		Projectile->FireInDirection(LaunchDirection);
//	}
//
//}

void ATowerPawn::AI_PlayerShooting(FVector TargetLocation)
{
	 
	Turn(TargetLocation);

    Fire();
}
