// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"


void UMainHUD::SetName(FText ItemName)
{
	ShowItemName->SetText(ItemName);
}

void UMainHUD::UpdateHUD(USurvivalHandlerComponent* SurvivalHandler)
{
	
}

void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();
}


