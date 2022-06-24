// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalHandlerComponent.h"

#include "Learning/Levels/DevLevel.h"

// Sets default values for this component's properties
USurvivalHandlerComponent::USurvivalHandlerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Health = 100;
	Temperature = 100;
	Thirst = 100;
	Hunger = 100;
}


// Called when the game starts
void USurvivalHandlerComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USurvivalHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

