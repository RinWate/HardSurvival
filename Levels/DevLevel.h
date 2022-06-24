// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "DevLevel.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API ADevLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ADevLevel();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AmbientTemperature;
};
