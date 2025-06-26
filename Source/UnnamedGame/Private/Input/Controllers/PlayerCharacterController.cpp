// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/Controllers/PlayerCharacterController.h"

#include <rapidjson/document.h>

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	if (const ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move);
	}
}

void APlayerCharacterController::Move(const FInputActionValue& Value)
{
	FVector2D InputVector = Value.Get<FVector2D>();
	if (ACharacter* ControlledCharacter = GetCharacter())
	{
		const FRotator Rotation = ControlledCharacter->GetActorRotation();
		const FVector Forward = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

		ControlledCharacter->AddMovementInput(Forward, InputVector.Y);
		ControlledCharacter->AddMovementInput(Right, InputVector.X);
	}
}
