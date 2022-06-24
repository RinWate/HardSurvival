// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EUseKind
{
 USE_PICKUP UMETA(DisplayName = "Pickup"),
 USE_BREAK UMETA(DisplayName = "Break"),
 USE_OPEN UMETA(DisplayName = "Open"),
 USE_ENTER UMETA(DisplayName = "Enter")
};