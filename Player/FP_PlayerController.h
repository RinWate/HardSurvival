// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Learning/UI/HUD/MainHUD.h"
#include "Learning/UI/Journal/PlayerJournal.h"
#include "FP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API AFP_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	UMainHUD* MainHUD;

	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	TSubclassOf<UMainHUD> MainHUDClass;

	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	UPlayerJournal* JournalHUD;

	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	TSubclassOf<UPlayerJournal> JournalClass;
	virtual void BeginPlay() override;
	
};
