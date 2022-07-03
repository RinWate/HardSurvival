// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/WidgetSwitcher.h"
#include "PlayerJournal.generated.h"

class AFP_Player;
/**
 * 
 */
UCLASS()
class LEARNING_API UPlayerJournal : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UButton* EquipTab;
	UPROPERTY(meta = (BindWidget))
	UButton* InventoryTab;
	UPROPERTY(meta = (BindWidget))
	UButton* SkillsTab;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* Background;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	int TabIndex;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	AFP_Player* PlayerRef;

	void Setup();
	
};
