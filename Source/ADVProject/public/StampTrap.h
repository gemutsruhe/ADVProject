// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StampTrap.generated.h"

UCLASS()
class ADVPROJECT_API AStampTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStampTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(VisibleAnywhere, Category = Collision)
	class UBoxComponent* colliComp;

	UPROPERTY(EditDefaultsOnly, Category = Move)
	FVector end;

	UPROPERTY(EditDefaultsOnly, Category = Move)
	FVector start;

	UPROPERTY(EditDefaultsOnly, Category = Move)
	float distance;

	UPROPERTY(EditDefaultsOnly, Category = Move)
	FVector dir;

};
