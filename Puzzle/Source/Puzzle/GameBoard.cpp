#include "GameBoard.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoard.h"

// Sets default values
AGameBoard::AGameBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

			}
			else if (ClickedPoint->CheckLoseCondition()) {
				ResetLevel();
				UE_LOG(LogTemp, Warning, TEXT("PRZEGRANA"));
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
	Super::BeginPlay();
	
}

// Called every frame
void AGameBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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



