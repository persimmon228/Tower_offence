// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"

ATankPawn::ATankPawn()
{

	Hitbox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//Create Spring Arm and Setup Attachment
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->TargetArmLength = 350.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.5f;

	//Create Camera and Setup Attachment
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

void ATankPawn::Move(float DistansToMove)
{
	FVector ConvertedVector((DistansToMove * 10), 0.0f, 0.0f);
	//Setting new Location
	AddActorLocalOffset(ConvertedVector);
}

void ATankPawn::Turn(float Rotation)
{
	FRotator ConvertedVector(0.0f, Rotation, 0.0f);
	//Setting new Rotation
	this->SetActorRotation((this->GetActorRotation() + ConvertedVector));
	MyTurretMesh->SetWorldRotation((MyTurretMesh->GetComponentRotation() - ConvertedVector));
}

void ATankPawn::TurrentRotation(float YawValue, float PitchValue)
{
	AddControllerYawInput(YawValue);
	AddControllerPitchInput(PitchValue);
	MyTurretMesh->SetWorldRotation((MyTurretMesh->GetComponentRotation() + FRotator(0.0f, (YawValue * 2.5), 0.0f)));
}

void ATankPawn::Tick(float DeltaTime)
{

}

