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
protected:
	virtual void NativeConstruct() override;
};
