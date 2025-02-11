// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameBoard.h"
#include "PlayerInputs.generated.h"

UCLASS()
class PUZZLE_API APlayerInputs : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerInputs();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function to handle mouse click
	void OnMouseClick();

private:
	// Function to process the mouse click
	void ProcessMouseClick();

	AGameBoard* GameBoard;

	void OnEscapeKeyPressed();
};
