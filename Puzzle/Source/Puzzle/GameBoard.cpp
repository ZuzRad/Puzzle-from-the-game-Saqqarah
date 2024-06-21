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
	UE_LOG(LogTemp, Warning, TEXT("Hit Point"));
	if (CurrentPoint)
	{
		FPuzzleElement* Element = CurrentPoint->CheckNearestPoints(ClickedPoint);

		if (Element && !UsedEdges.Contains(Element->Edge))
		{
			CurrentPoint->ChangeState(2);
			CurrentPoint = ClickedPoint;
			CurrentPoint->ChangeState(1);

			UsedEdges.Add(Element->Edge);
			Element->Edge->ChangeState(1);
			if (CheckWinCondition()) 
			{
				UE_LOG(LogTemp, Warning, TEXT("WYGRANA"));
			}
		}
	}
	else 
	{
		CurrentPoint = ClickedPoint;
		ClickedPoint->ChangeState(1);
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
	if (sizeof(UsedEdges) == EdgesNumber) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


