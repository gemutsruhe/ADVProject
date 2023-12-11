// Fill out your copyright notice in the Description page of Project Settings.


#include "GameoverTrigger.h"
#include <Components/BoxComponent.h>


// Sets default values
AGameoverTrigger::AGameoverTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	colliComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("GameoverTrigger"));
	
}

// Called when the game starts or when spawned
void AGameoverTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameoverTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameoverTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	
}
