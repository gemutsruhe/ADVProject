// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include <Components/CapsuleComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	colliComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = colliComp;
	colliComp->SetRelativeScale3D(FVector(12.0f));
	colliComp->SetCapsuleHalfHeight(35.0f);
	colliComp->SetCapsuleRadius(1.0f);
	colliComp->SetCollisionProfileName(TEXT("Arrow"));

	bodyComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/Props/Arrow.Arrow'"));
	if (tempMesh.Succeeded()) {
		bodyComp->SetStaticMesh(tempMesh.Object);
	}
	bodyComp->SetupAttachment(colliComp);

	bodyComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	movementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	movementComp->SetUpdatedComponent(colliComp);

	movementComp->InitialSpeed = 0;
	movementComp->MaxSpeed = 5000;
	movementComp->bShouldBounce = false;
	
	
}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArrow::Shoot(const FVector& Direction) {
	movementComp->InitialSpeed = 5000;
	movementComp->Velocity = Direction * movementComp->InitialSpeed;
	isShooted = true;
}

bool AArrow::bCanInteract() {
	if (movementComp->Velocity == FVector(0, 0, 0) && isShooted) {
		return true;
	}
	else
		return false;
}