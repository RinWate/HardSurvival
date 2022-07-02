// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Gamemode.h"

#include "Kismet/GameplayStatics.h"
#include "Learning/Player/FP_Player.h"
#include "Learning/Player/FP_PlayerController.h"

AFP_Gamemode::AFP_Gamemode()
{
	DefaultPawnClass = AFP_Player::StaticClass();
	PlayerControllerClass = AFP_PlayerController::StaticClass();
}

void AFP_Gamemode::BeginPlay()
{
	Super::BeginPlay();
	
}
