// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleElement.generated.h"

class APuzzlePoint;
class APuzzleEdge;

USTRUCT(BlueprintType)
struct FPuzzleElement
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle Element")
    APuzzlePoint* Point;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle Element")
    APuzzleEdge* Edge;
};