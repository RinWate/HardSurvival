// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_PlayerController.h"

void AFP_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		if (MainHUDClass)
		{
			if (!MainHUD)
			{
				//MainHUD = CreateWidget<UMainHUD>(this, MainHUDClass);
				
			}
			MainHUD->AddToViewport();
		}
	}
}
