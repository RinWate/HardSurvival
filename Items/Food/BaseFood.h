// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Learning/Items/BaseItem.h"
#include "BaseFood.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API ABaseFood : public ABaseItem
{
	GENERATED_BODY()

public:
	ABaseFood();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Food Settings")
	float Calories;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Food Settings")
	float Hydration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food Settings")
	bool isHot;
	
};
