// Fill out your copyright notice in the Description page of Project Settings.


#include "RUtility.h"

void RUtility::PrintMessage(FString Message)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);
	}
}
