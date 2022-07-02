// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FP_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AFP_Gamemode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFP_Gamemode();

	virtual void BeginPlay() override;
	
};
