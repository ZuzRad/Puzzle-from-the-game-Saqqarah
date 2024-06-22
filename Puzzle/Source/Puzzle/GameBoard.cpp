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

	AudioComponent = CreateDefaultSubobject<UAwakeAudioPlayer>(TEXT("AudioComponent"));
}

void AGameBoard::CheckPointClicked(APuzzlePoint* ClickedPoint)
{
	if (CurrentPoint)
	{
		FPuzzleElement* Element = CurrentPoint->CheckNearestPoints(ClickedPoint);

		if (Element && CheckCurrentEdge(Element->Edge))
		{
			PlayFromAudioComponent(HitPoint);

			CurrentPoint->ChangeState(2);
			ChangeCurrentPoint(ClickedPoint);
			UsedEdges++;

			if (CheckWinCondition()) 
			{
				FVector WorldOffset(0.f, 50.f, 0.f);
				AddActorWorldOffset(WorldOffset, false, nullptr, ETeleportType::None);

				PlayFromAudioComponent(WinSound);
			}
			else if (ClickedPoint->CheckLoseCondition()) 
			{
				PlayFromAudioComponent(LoseSound);
				
				GetWorld()->GetTimerManager().SetTimer(ResetTimerHandle, this, &AGameBoard::DelayedResetLevel, 2.0f, false);
			}
		}
	}
	else 
	{
		PlayFromAudioComponent(HitPoint);
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

void AGameBoard::PlayFromAudioComponent(USoundBase* Sound)
{
	AudioComponent->SoundToPlay = Sound;
	AudioComponent->PlaySound();
}



// Called when the game starts or when spawned
void AGameBoard::BeginPlay()
{
	Super::BeginPlay();
	UsedEdges = 0;
	PrimarySprite->SetSprite(HidingPlace);
	KeySprite->SetSprite(Key);

	PlayFromAudioComponent(Music);
}

// Called every frame
void AGameBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameBoard::TakeKey()
{
	PlayFromAudioComponent(TakeKeySound);
	KeySprite->SetHiddenInGame(true);
}

void AGameBoard::DelayedResetLevel()
{
	ResetLevel();
}

bool AGameBoard::CheckWinCondition()
{
	if (UsedEdges == EdgesNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}



