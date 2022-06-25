// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "Learning/Player/FP_Player.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UInventory : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	USurvivalHandlerComponent* SurvivalHandler;
	
	UPROPERTY(meta = (BindWidget))
	UGridPanel* InventoryPanel;

	UPROPERTY()
	TArray<FItemStructure> InItems;

protected:
	virtual void NativeConstruct() override;
};
