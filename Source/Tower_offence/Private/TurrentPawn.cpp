// Fill out your copyright notice in the Description page of Project Settings.


#include "TurrentPawn.h"

// Sets default values
ATurrentPawn::ATurrentPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Hitbox = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Hitbox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Hitbox->SetCollisionResponseToAllChannels(ECR_Ignore);
	Hitbox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = Hitbox;
	SetRootComponent(Hitbox);
	

	MyBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	MyBaseMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MyTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	MyTurretMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MyProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	MyProjectileSpawnPoint->AttachToComponent(MyTurretMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATurrentPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

float ATurrentPawn::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	HP -= DamageAmount;
	if (HP<=0)
	{
		GameResultat();
	}
	return DamageAmount;
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

