// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSprite.h"
#include "PuzzleElement.h"
#include "PaperSpriteComponent.h"
#include "PuzzlePoint.generated.h"


UCLASS()
class PUZZLE_API APuzzlePoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzlePoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeState(int State);

	int CurrentState;

	bool CheckNearestPoints(APuzzlePoint* ClickedPoint);

	// Editable sprites in Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	UPaperSprite* UsedSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	UPaperSprite* ActiveSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	UPaperSprite* BaseSprite;

	// Reference to the PaperSprite component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	class UPaperSpriteComponent* PrimarySprite;

private:
	// Function to change sprite
	void SetActiveSprite(UPaperSprite* NewSprite);

	//// Array of points
	//UPROPERTY(EditAnywhere)
	//TArray<APuzzlePoint*> NearestPoints;

	//// Array of edges
	//UPROPERTY(EditAnywhere)
	//TArray<APuzzleEdge*> NearestEdges;
	UPROPERTY(EditAnywhere, Category = "Puzzle Elements")
	TArray<FPuzzleElement> PuzzleElements;

};
