// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"


void UMainHUD::SetName(FText ItemName)
{
	ShowItemName->SetText(ItemName);
}

void UMainHUD::UpdateHUD(USurvivalHandlerComponent* SurvivalHandler)
{
	HealthBar->SetPercent(SurvivalHandler->Health / 100);
	TempBar->SetPercent(SurvivalHandler->Temperature / 100);
	FoodBar->SetPercent(SurvivalHandler->Hunger / 100);
	ThirstBar->SetPercent(SurvivalHandler->Thirst / 100);
}

void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();
}


