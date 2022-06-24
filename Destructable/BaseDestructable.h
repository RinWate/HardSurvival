// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Learning/Items/BaseItem.h"
#include "BaseDestructable.generated.h"

UCLASS()
class LEARNING_API ABaseDestructable : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseDestructable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ABaseItem*> Reward;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
