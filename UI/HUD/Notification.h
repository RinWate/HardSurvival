// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Notification.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UNotification : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* NotificationIcon;
	UPROPERTY(BlueprintReadWrite)
	FString NotificationText;
	UPROPERTY(BlueprintReadWrite)
	FString NotificationName;
	UPROPERTY(BlueprintReadWrite)
	float ShowTime = 1;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* Icon;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Name;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Type;
	
};
