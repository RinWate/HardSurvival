// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Learning/Items/BaseItem.h"
#include "Learning/Player/SurvivalHandlerComponent.h"
#include "MainHUD.generated.h"

class AFP_Player;
/**
 * 
 */
UCLASS()
class LEARNING_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetName(FText ItemName);
	void SetActionName(ABaseItem* Item);
	void UpdateHUD(USurvivalHandlerComponent* SurvivalHandler);

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	AFP_Player* PlayerRef;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShowItemName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ActionName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* NotificationQuery;

	void Setup();
protected:
	virtual void NativeConstruct() override;
};
