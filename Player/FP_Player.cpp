// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Player.h"

#include "DrawDebugHelpers.h"
#include "FP_PlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Learning/Items/BaseItem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFP_Player::AFP_Player()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(40, 90);
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	SurvivalHandler = CreateDefaultSubobject<USurvivalHandlerComponent>("SurvivalHandler");
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->bUsePawnControlRotation = true;
	
	Camera->SetRelativeLocation(FVector(0.0, 0, 80));
	Camera->SetVisibility(true);
	Camera->SetHiddenInGame(false);

	ConstructorHelpers::FClassFinder<UUserWidget> MainHUDFinder(TEXT("/Game/UI/UI_MainHUD"));
	MainHUDClass = MainHUDFinder.Class;
	ConstructorHelpers::FClassFinder<UUserWidget> JournalHUDFinder(TEXT("/Game/UI/Journal/UI_PlayerJournal"));
	JournalHUDClass = JournalHUDFinder.Class;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	MouseSensitivity = 30.f;

	bisInputEnable = true;
}

void AFP_Player::MoveRight(float value)
{
	if (!bisInputEnable) return;
		AddMovementInput(GetActorRightVector(), value);
}

void AFP_Player::MoveForward(float value)
{
	if (!bisInputEnable) return;
	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yaw_rotation(0, rotation.Yaw, 0);

	const FVector direction = FRotationMatrix(yaw_rotation).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, value);
}

void AFP_Player::LookUp(float value)
{
	if (!bisInputEnable) return;
	AddControllerYawInput(value * MouseSensitivity * GetWorld()->GetDeltaSeconds());
}

void AFP_Player::Turn(float value)
{
	if (!bisInputEnable) return;
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

void AFP_Player::OpenJournal()
{
	bisInputEnable = !bisInputEnable;
	if (!bisInputEnable)
	{
		JournalHUD = CreateWidget<UPlayerJournal>(UGameplayStatics::GetPlayerController(GetWorld(), 0), JournalHUDClass);
		JournalHUD->AddToViewport();
		MainHUD->SetVisibility(ESlateVisibility::Hidden);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
	} else
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(false);
		MainHUD->SetVisibility(ESlateVisibility::Visible);
		JournalHUD->RemoveFromParent();
	}
}

void AFP_Player::Use()
{
	if (LookAt == nullptr || !bisInputEnable) return;
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

void AFP_Player::LookTrace()
{
	if (!bisInputEnable) return;
	FHitResult hit;
	const FVector StartPoint = Camera->GetComponentLocation();

	const FVector ForwardVector = Camera->GetForwardVector();
	FVector EndPoint = ((ForwardVector * TraceLength) + StartPoint);
	FCollisionQueryParams Params;

	if (GetWorld()->LineTraceSingleByObjectType(hit, StartPoint, EndPoint, ECC_GameTraceChannel1, Params))
	{
		if (hit.bBlockingHit)
		{
			LookAt = Cast<ABaseItem>(hit.GetActor());
			MainHUD->SetName(LookAt->Display_name);
			MainHUD->SetActionName(LookAt);
		}
	} else
	{
		LookAt = nullptr;
		MainHUD->SetName(FText::FromString(""));
		MainHUD->SetActionName(nullptr);
	}
}

USurvivalHandlerComponent* AFP_Player::GetSurvivalHandler()
{
	return SurvivalHandler;
}

UInventoryComponent* AFP_Player::GetInventory()
{
	return Inventory;
}

// Called when the game starts or when spawned
void AFP_Player::BeginPlay()
{
	Super::BeginPlay();
	MainHUD = CreateWidget<UMainHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainHUDClass);
	MainHUD->AddToViewport();
}

// Called every frame
void AFP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LookTrace();
	MainHUD->UpdateHUD(SurvivalHandler);
}

// Called to bind functionality to input
void AFP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFP_Player::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFP_Player::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFP_Player::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AFP_Player::Turn);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFP_Player::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFP_Player::SprintEnd);
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AFP_Player::Use);
	PlayerInputComponent->BindAction("OpenJournal", IE_Pressed, this, &AFP_Player::OpenJournal);
}

