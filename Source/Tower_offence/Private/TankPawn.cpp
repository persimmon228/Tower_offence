// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"

ATankPawn::ATankPawn()
{

	Hitbox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//Create Spring Arm and Setup Attachment
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->TargetArmLength = 250.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.5f;

	//Create Camera and Setup Attachment
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

void ATankPawn::Move(float DistansToMove)
{
	FVector ConvertedVector(0.0f, (DistansToMove*10), 0.0f);
	//Setting new Location
	AddActorLocalOffset(ConvertedVector);
}

void ATankPawn::Turn(float Rotation)
{
	FRotator ConvertedVector(0.0f, Rotation, 0.0f);
	//Setting new Rotation
	this->SetActorRotation((this->GetActorRotation() + ConvertedVector));
}

void ATankPawn::TurrentRotation()
{
	
}

void ATankPawn::Tick(float DeltaTime)
{
	FHitResult HitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	FRotator NewRotation = HitResult.ImpactPoint.Rotation();
	FRotator CurrentRotation = MyTurretMesh->GetComponentRotation();
	FRotator RotationDifference = NewRotation - CurrentRotation;
	RotationDifference *= 0.01f;
	FRotator FinalRotation = CurrentRotation + RotationDifference;
	MyTurretMesh->SetWorldRotation(FinalRotation);
}

