// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UInventory : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UGridPanel* InventoryPanel;

	virtual void NativeConstruct() override;
};
