// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"


void UMainHUD::SetName(FText ItemName)
{
	ShowItemName->SetText(ItemName);
}

void UMainHUD::SetActionName(ABaseItem* Item)
{
	if (Item == nullptr)
	{
		ActionName->SetText(FText::FromString(""));
		return;
	}
	switch (Item->ActionName)
	{
	case USE_OPEN: ActionName->SetText(FText::FromString("Pickup"));
		break;
	case USE_BREAK: ActionName->SetText(FText::FromString("Разрушить"));
		break;
	case USE_ENTER: ActionName->SetText(FText::FromString("Войти"));
		break;
	case USE_PICKUP: ActionName->SetText(FText::FromString("Подобрать"));
		break;
	default: break;
	}
}

void UMainHUD::UpdateHUD(USurvivalHandlerComponent* SurvivalHandler)
{
	
}

void UMainHUD::Setup()
{
	this->AddToViewport();
}

void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();
}


