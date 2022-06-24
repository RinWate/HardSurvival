// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Learning/Items/ItemStructure.h"
#include "Learning/Items/BaseItem.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNING_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(ABaseItem* input);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(int index);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItemStructure GetItem(int index);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FItemStructure> GetItems();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory")
	int GetItemsCount();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItemStructure GetItemStructure(ABaseItem* item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	float GetWeight();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateWeight();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	float MaxWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	float CurrentWeight;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FItemStructure> Items;
protected:
	virtual void BeginPlay() override;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
