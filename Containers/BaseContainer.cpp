// Fill out your copyright notice in the Description page of Project Settings.


#include "Learning/Containers/BaseContainer.h"
#include "Learning/Inventory/InventoryComponent.h"

// Sets default values
ABaseContainer::ABaseContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Model = CreateDefaultSubobject<UStaticMeshComponent>("Model");
	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
}

// Called when the game starts or when spawned
void ABaseContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

