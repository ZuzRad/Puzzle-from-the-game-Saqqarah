// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInputs.h"
#include "PuzzlePoint.h"
#include <Kismet/GameplayStatics.h>

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

	UWorld* World = GetWorld();
	if (World)
	{
		GameBoard = Cast<AGameBoard>(UGameplayStatics::GetActorOfClass(World, AGameBoard::StaticClass()));
	}
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
	}
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

void APlayerInputs::OnMouseClick()
{
	ProcessMouseClick();
}

void APlayerInputs::ProcessMouseClick()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

		if (HitResult.bBlockingHit)
		{
			APuzzlePoint* ClickedPoint = Cast<APuzzlePoint>(HitResult.GetActor());
			if (ClickedPoint)
			{
				GameBoard->CheckPointClicked(ClickedPoint);
			}
		}
	}
}

