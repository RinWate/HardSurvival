// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Learning/Enumeration/EUseKind.h"
#include "FP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AFP_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
};
