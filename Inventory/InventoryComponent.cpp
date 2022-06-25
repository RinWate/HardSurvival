// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include <string>

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::AddItem(ABaseItem* item)
{
	Items.Add(GetItemStructure(item));
	UpdateWeight();
}

void UInventoryComponent::RemoveItem(int index)
{
	Items.RemoveAt(index);
	UpdateWeight();
}

FItemStructure UInventoryComponent::GetItem(int index)
{
	return Items[index];
}

TArray<FItemStructure> UInventoryComponent::GetItems()
{
	return Items;
}

int UInventoryComponent::GetItemsCount()
{
	return Items.Num();
}

FItemStructure UInventoryComponent::GetItemStructure(ABaseItem* item)
{
	FItemStructure result;
	result.Name = item->Display_name;
	result.Description = item->Description;
	result.Icon = item->Icon;
	result.Durability = item->Durability;
	result.Weight = item->Weight;
	result.ItemClass = item->GetClass();
	return result;
}

FItemStructure UInventoryComponent::GetItemStructureByIndex(int Index)
{
	return Items[Index];
}

float UInventoryComponent::GetWeight()
{
	return CurrentWeight;
}

void UInventoryComponent::UpdateWeight()
{
	float local_weight = 0;
	for (const auto& item : Items)
	{
		local_weight += item.Weight;
	}
	CurrentWeight = local_weight;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

