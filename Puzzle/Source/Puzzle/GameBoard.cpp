#include "GameBoard.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoard.h"

// Sets default values
AGameBoard::AGameBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimarySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PrimarySprite"));
	PrimarySprite->SetupAttachment(RootComponent);

	KeySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("KeySprite"));
	KeySprite->SetupAttachment(PrimarySprite);
}

void AGameBoard::CheckPointClicked(APuzzlePoint* ClickedPoint)
{
	if (CurrentPoint)
	{
		FPuzzleElement* Element = CurrentPoint->CheckNearestPoints(ClickedPoint);

		if (Element && !UsedEdges.Contains(Element->Edge))
		{
			CurrentPoint->ChangeState(2);
			ChangeCurrentPoint(ClickedPoint);

			UsedEdges.Add(Element->Edge);
			Element->Edge->ChangeState(1);
			if (CheckWinCondition()) 
			{
				UE_LOG(LogTemp, Warning, TEXT("WYGRANA"));
				FVector WorldOffset(-5.f, 40.f, 25.f);
				AddActorWorldOffset(WorldOffset, false, nullptr, ETeleportType::None);
			}
			else if (ClickedPoint->CheckLoseCondition()) {
				ResetLevel();
			}
		}
	}
	else 
	{
		ChangeCurrentPoint(ClickedPoint);
	}
}



bool AGameBoard::CheckCurrentEdge(APuzzleEdge* Edge)
{
	if (Edge->ReturnState() == 0)
	{
		Edge->ChangeState(1);
		return true;
	}
	else 
	{
		return false;
	}
}

void AGameBoard::ChangeCurrentPoint(APuzzlePoint* ClickedPoint)
{
	CurrentPoint = ClickedPoint;
	CurrentPoint->ChangeState(1);
}

void AGameBoard::ResetLevel()
{
	UWorld* World = GetWorld();
	if (World)
	{
		FName CurrentLevelName = *World->GetName();
		UGameplayStatics::OpenLevel(World, CurrentLevelName);
	}
}



// Called when the game starts or when spawned
void AGameBoard::BeginPlay()
{
	//FVector WorldOffset(0.f, 45.f, 0.f);
	//AddActorWorldOffset(WorldOffset, false, nullptr, ETeleportType::None);
	Super::BeginPlay();

	PrimarySprite->SetSprite(HidingPlace);
	KeySprite->SetSprite(Key);
}

// Called every frame
void AGameBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameBoard::TakeKey()
{
	UE_LOG(LogTemp, Warning, TEXT("Wez klucz"));
	KeySprite->SetHiddenInGame(true);
	//KeySprite->SetWorldLocation(FVector(0.f, 0.f, 0.f))
	// KeySprite->DestroyComponent();
}

bool AGameBoard::CheckWinCondition()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of used edges: %d"), UsedEdges.Num());
	if (UsedEdges.Num() == EdgesNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}



