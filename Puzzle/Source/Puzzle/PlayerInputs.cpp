// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInputs.h"

// Sets default values
APlayerInputs::APlayerInputs()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerInputs::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerInputs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerInputs::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

