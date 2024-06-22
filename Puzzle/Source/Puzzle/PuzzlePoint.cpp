// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePoint.h"

// Sets default values
APuzzlePoint::APuzzlePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimarySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PrimarySprite"));

	PrimarySprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APuzzlePoint::BeginPlay()
{
	Super::BeginPlay();
	ChangeState(0);
	OriginalLocation = GetActorLocation();
	ShakeCount = 0;
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

FPuzzleElement* APuzzlePoint::CheckNearestPoints(APuzzlePoint* ClickedPoint)
{
	for (FPuzzleElement& Element : PuzzleElements)
	{
		if (Element.Point == ClickedPoint)
		{
			return &Element;
		}
	}
	StartShake();
	return nullptr;
}

bool APuzzlePoint::CheckLoseCondition()
{
	for (FPuzzleElement& Element : PuzzleElements)
	{
		if (Element.Edge->ReturnState() == 0)
		{
			return false;
		}
	}
	return true;
}



void APuzzlePoint::SetActiveSprite(UPaperSprite* NewSprite)
{
	if (PrimarySprite && NewSprite)
	{
		PrimarySprite->SetSprite(NewSprite);
	}
}

void APuzzlePoint::StartShake()
{
	ShakeCount = 0;
	GetWorld()->GetTimerManager().SetTimer(ShakeTimerHandle, this, &APuzzlePoint::PerformShake, 0.05f, true);
}

void APuzzlePoint::PerformShake()
{
	if (ShakeCount < 10)
	{
		FVector ShakeOffset = FVector(FMath::RandRange(-5, 5), FMath::RandRange(-5, 5), 0);
		SetActorLocation(OriginalLocation + ShakeOffset);
		ShakeCount++;
	}
	else
	{
		StopShake();
	}
}

void APuzzlePoint::StopShake()
{
	SetActorLocation(OriginalLocation);
	GetWorld()->GetTimerManager().ClearTimer(ShakeTimerHandle);
}