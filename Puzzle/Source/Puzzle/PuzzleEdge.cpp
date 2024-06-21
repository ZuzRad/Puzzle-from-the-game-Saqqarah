// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleEdge.h"

// Sets default values
APuzzleEdge::APuzzleEdge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzleEdge::BeginPlay()
{
	Super::BeginPlay();
	ChangeState(0);
}

// Called every frame
void APuzzleEdge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzleEdge::ChangeState(int State)
{
	CurrentState = State;
	if (State == 1) 
	{
		ShowEdge();
	}
}

int APuzzleEdge::ReturnState()
{
	return CurrentState;
}

void APuzzleEdge::ShowEdge()
{
	SetActorHiddenInGame(false);
	UE_LOG(LogTemp, Warning, TEXT("SHOW EDGE"));
}

