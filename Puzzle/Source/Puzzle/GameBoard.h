// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzlePoint.h"
#include "PuzzleEdge.h"
#include "GameBoard.generated.h"

UCLASS()
class PUZZLE_API AGameBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameBoard();

	void CheckPointClicked(APuzzlePoint* ClickedPoint);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	APuzzlePoint* CurrentPoint;

	UPROPERTY()
	TArray<APuzzleEdge*> UsedEdges;

	UPROPERTY(EditAnywhere)
	int EdgesNumber;

};
