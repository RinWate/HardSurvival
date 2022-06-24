// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "Learning/Enumeration/EUseKind.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Model = CreateDefaultSubobject<UStaticMeshComponent>("Item Model");
	Scene = CreateDefaultSubobject<USceneComponent>("Pivot");
	RootComponent = Scene;
	Model->SetupAttachment(Scene);

	Display_name.FromString("Default");
	Description.FromString("No");
	Weight = 1.0;
	Durability = 100;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

