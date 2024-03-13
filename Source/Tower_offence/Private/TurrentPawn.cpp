// Fill out your copyright notice in the Description page of Project Settings.


#include "TurrentPawn.h"

// Sets default values
ATurrentPawn::ATurrentPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(Hitbox);
	Hitbox = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));

	MyBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	MyBaseMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MyTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	MyTurretMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MyProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	MyProjectileSpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATurrentPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurrentPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurrentPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

