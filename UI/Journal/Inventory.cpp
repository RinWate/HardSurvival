// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

#include "Kismet/GameplayStatics.h"
#include "Learning/Player/FP_Player.h"

void UInventory::NativeConstruct()
{
	Super::NativeConstruct();
	auto Inventory = Cast<AFP_Player>(GetOwningPlayerPawn())->GetInventory();
	
	InventoryPanel->ClearChildren();
	for (int i = 0; i < Inventory->GetItemsCount(); i++)
	{
		const auto NewSlot = CreateWidget<UInventorySlot>(UGameplayStatics::GetPlayerController(GetWorld(), 0), UInventorySlot::StaticClass());
		const auto CurrentItem = Inventory->GetItemStructureByIndex(i);
		NewSlot->Weight->SetText(FText::FromString(FString::SanitizeFloat(CurrentItem.Weight)));
		NewSlot->Durability->SetText(FText::FromString(FString::SanitizeFloat(CurrentItem.Durability)));
		NewSlot->SlotIcon->SetBrushFromTexture(CurrentItem.Icon);
		InventoryPanel->AddChildToGrid(NewSlot);
	}
}