// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Learning/Player/SurvivalHandlerComponent.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetName(FText ItemName);
	void UpdateHUD(USurvivalHandlerComponent* SurvivalHandler);
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShowItemName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* NotificationQuery;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* TempBar;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* FoodBar;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ThirstBar;
protected:
	virtual void NativeConstruct() override;
};
