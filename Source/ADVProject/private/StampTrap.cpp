// Fill out your copyright notice in the Description page of Project Settings.


#include "StampTrap.h"
#include <Components/BoxComponent.h>
#include "ADVPlayer.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AStampTrap::AStampTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	colliComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("BlockOnlyDynamic"));
	end = FVector(160, 0, 90);

}

// Called when the game starts or when spawned
void AStampTrap::BeginPlay()
{
	Super::BeginPlay();
	start = GetActorLocation();
	dir = end - start;

}

// Called every frame
void AStampTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isSolved) {
		distance = FVector::Distance(GetActorLocation(), end);
		if (distance > 10) {
			FVector vt = dir * 0.02 * DeltaTime;
			FVector P = GetActorLocation() + vt;
			SetActorLocation(P);
		}
	}


}

