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

	// Show mouse cursor
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
	}
	UE_LOG(LogTemp, Warning, TEXT("DZIALA"));


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

	// Bind mouse click event
	PlayerInputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &APlayerInputs::OnMouseClick);

}

// Function to handle mouse click
void APlayerInputs::OnMouseClick()
{
	ProcessMouseClick();
}

// Function to process the mouse click
void APlayerInputs::ProcessMouseClick()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

		if (HitResult.bBlockingHit)
		{
			// Log the name of the clicked actor
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor"));

			// Here you can add the logic to interact with the clicked actor, e.g., process puzzle elements
		}
	}
}

