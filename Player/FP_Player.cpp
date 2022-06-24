// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Player.h"

#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Learning/Items/BaseItem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"

// Sets default values
AFP_Player::AFP_Player()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(40, 90);
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	SurvivalHandler = CreateDefaultSubobject<USurvivalHandlerComponent>("SurvivalHandler");
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->bUsePawnControlRotation = true;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	MouseSensitivity = 30.f;
}

void AFP_Player::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AFP_Player::MoveForward(float value)
{
	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yaw_rotation(0, rotation.Yaw, 0);

	const FVector direction = FRotationMatrix(yaw_rotation).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, value);
}

void AFP_Player::LookUp(float value)
{
	AddControllerYawInput(value * MouseSensitivity * GetWorld()->GetDeltaSeconds());
}

void AFP_Player::Turn(float value)
{
	AddControllerPitchInput(value * MouseSensitivity * GetWorld()->GetDeltaSeconds());
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AFP_Player::SprintStart()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AFP_Player::SprintEnd()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AFP_Player::Use()
{
	if (LookAt == nullptr) return;
	switch (KindOfUse)
	{
	case USE_PICKUP:
		{
			Inventory->AddItem(LookAt);
			OnPick(Inventory->GetItemStructure(LookAt));
			LookAt->Destroy();
		}
	default: break;
	}
}

void AFP_Player::OpenInventory()
{
	
}

void AFP_Player::LookTrace()
{
	FHitResult hit;
	const FVector StartPoint = Camera->GetComponentLocation();

	const FVector ForwardVector = Camera->GetForwardVector();
	FVector EndPoint = ((ForwardVector * TraceLength) + StartPoint);
	FCollisionQueryParams Params;

	//DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByObjectType(hit, StartPoint, EndPoint, ECC_GameTraceChannel1, Params))
	{
		if (hit.bBlockingHit)
		{
			LookAt = Cast<ABaseItem>(hit.GetActor());
			GetPlayerController()->MainHUD->SetName(LookAt->Display_name);
		}
	} else
	{
		LookAt = nullptr;
		GetPlayerController()->MainHUD->SetName(FText::FromString(""));
	}
}

USurvivalHandlerComponent* AFP_Player::GetSurvivalHandler()
{
	return SurvivalHandler;
}

AFP_PlayerController* AFP_Player::GetPlayerController()
{
	return Cast<AFP_PlayerController>(GetController());
}

// Called when the game starts or when spawned
void AFP_Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LookTrace();
	GetPlayerController()->MainHUD->UpdateHUD(SurvivalHandler);
}

// Called to bind functionality to input
void AFP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFP_Player::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFP_Player::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFP_Player::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFP_Player::SprintEnd);
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AFP_Player::Use);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AFP_Player::OpenInventory);
}

