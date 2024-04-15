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
	FVector ConvertedVector (DistansToMove, 0.0f, 0.0f);
	//Setting new Location
	this->SetActorLocation((this->GetActorForwardVector() + ConvertedVector));
}

void ATankPawn::Turn(float Rotation)
{
	FRotator ConvertedVector (Rotation, 0.0f, 0.0f);
	//Setting new Rotation
	this->SetActorRotation((this->GetActorRotation() + ConvertedVector));
}

void ATankPawn::TurrentRotation()
{
	FHitResult HitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	MyTurretMesh->SetWorldRotation(HitResult.ImpactNormal.Rotation());
	SpringArm->SetWorldRotation(HitResult.ImpactNormal.Rotation());
}

