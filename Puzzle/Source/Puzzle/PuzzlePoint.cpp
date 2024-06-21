// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePoint.h"

// Sets default values
APuzzlePoint::APuzzlePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimarySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PrimarySprite"));

	PrimarySprite->SetupAttachment(RootComponent);
	//AttachTo
}

// Called when the game starts or when spawned
void APuzzlePoint::BeginPlay()
{
	Super::BeginPlay();
	ChangeState(0);
}

// Called every frame
void APuzzlePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzlePoint::ChangeState(int State)
{
	CurrentState = State;
	switch (State) {
		case 0:
			SetActiveSprite(BaseSprite);
			break;
		case 1:
			SetActiveSprite(ActiveSprite);
			break;
		case 2:
			SetActiveSprite(UsedSprite);
			break;
		default:
			break;
	}
}



void APuzzlePoint::SetActiveSprite(UPaperSprite* NewSprite)
{
	if (PrimarySprite && NewSprite)
	{
		PrimarySprite->SetSprite(NewSprite);
	}
}

