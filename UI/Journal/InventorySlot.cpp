// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlot.h"

void UInventorySlot::SetupSlot(FItemStructure InItem)
{
	SlotIcon->SetBrushFromTexture(InItem.Icon);
	Weight->SetText(FText::FromString(FString::SanitizeFloat(InItem.Weight)));
	Durability->SetText(FText::FromString(FString::SanitizeFloat(InItem.Durability)));
}
