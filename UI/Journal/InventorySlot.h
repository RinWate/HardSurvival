// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Learning/Items/ItemStructure.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* SlotButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* SlotIcon;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* Durability;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* Weight;

	UFUNCTION(BlueprintCallable)
	void SetupSlot(FItemStructure InItem);
};