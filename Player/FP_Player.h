// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SurvivalHandlerComponent.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Learning/Enumeration/EUseKind.h"
#include "Learning/Inventory/InventoryComponent.h"
#include "Learning/UI/HUD/MainHUD.h"
#include "Learning/UI/Journal/Tabs/InventorySlot.h"
#include "Learning/UI/Journal/PlayerJournal.h"
#include "FP_Player.generated.h"

UCLASS()
class LEARNING_API AFP_Player : public ACharacter
{
	GENERATED_BODY()

public:
	AFP_Player();
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float MouseSensitivity;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float WalkSpeed = 300;
	UPROPERTY(EditAnywhere, Category = "Settings")
	float SprintSpeed = 600;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float TraceLength = 300;

	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	UMainHUD* MainHUD;

	UPROPERTY(BlueprintReadWrite, Category = "User Interface")
	UPlayerJournal* JournalHUD;

	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<UPlayerJournal> JournalHUDClass;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	UInventoryComponent* Inventory;
	
	UPROPERTY(BlueprintReadOnly)
	ABaseItem* LookAt;

	UPROPERTY()
	USurvivalHandlerComponent* SurvivalHandler;
	TEnumAsByte<EUseKind> KindOfUse;
	
	void MoveRight(float value);
	void MoveForward(float value);
	void LookUp(float value);
	void Turn(float value);
	void SprintStart();
	void SprintEnd();
	void OpenInventory();
	void Use();
	void LookTrace();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	USurvivalHandlerComponent* GetSurvivalHandler();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UInventoryComponent* GetInventory();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnPick(FItemStructure item);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
