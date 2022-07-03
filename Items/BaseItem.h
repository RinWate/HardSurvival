// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemStructure.h"
#include "GameFramework/Actor.h"
#include "Learning/Enumeration/EUseKind.h"
#include "BaseItem.generated.h"

UCLASS()
class LEARNING_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FText Display_name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TEnumAsByte<EUseKind> ActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = 1, ClampMax = 32))
	int StackSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = 0))
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = 0))
	float Durability;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
