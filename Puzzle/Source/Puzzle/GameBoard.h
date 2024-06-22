// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzlePoint.h"
#include "PuzzleEdge.h"
#include "Kismet/GameplayStatics.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "PuzzleElement.h"
#include "AwakeAudioPlayer.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	UPaperSprite* HidingPlace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	UPaperSprite* Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	class UPaperSpriteComponent* PrimarySprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	class UPaperSpriteComponent* KeySprite;

	UPROPERTY(EditAnywhere, Category = "Audio")
	UAwakeAudioPlayer* AudioComponent;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* WinSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* LoseSound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* TakeKeySound;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* HitPoint;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* Music;

	void TakeKey();


private:
	UPROPERTY()
	APuzzlePoint* CurrentPoint;

	int UsedEdges;

	UPROPERTY(EditAnywhere)
	int EdgesNumber;

	FTimerHandle ResetTimerHandle;

	void DelayedResetLevel();

	bool CheckWinCondition();

	bool CheckCurrentEdge(APuzzleEdge* Edge);

	void ChangeCurrentPoint(APuzzlePoint* ClickedPoint);

	void ResetLevel();

	void PlayFromAudioComponent(USoundBase* Sound);

};
