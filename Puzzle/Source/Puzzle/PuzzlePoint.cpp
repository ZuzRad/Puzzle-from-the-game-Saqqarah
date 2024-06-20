// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePoint.h"

// Sets default values
APuzzlePoint::APuzzlePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzlePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzlePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

