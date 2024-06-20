// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePoint.h"

// Sets default values
ABasePoint::ABasePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

