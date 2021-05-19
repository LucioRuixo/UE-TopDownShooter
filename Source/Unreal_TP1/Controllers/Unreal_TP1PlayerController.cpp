// Fill out your copyright notice in the Description page of Project Settings.


#include "Unreal_TP1PlayerController.h"

void AUnreal_TP1PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AUnreal_TP1PlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AUnreal_TP1PlayerController::MoveRight);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &AUnreal_TP1PlayerController::Shoot);
}

void AUnreal_TP1PlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator Yaw(0.0f, Rotation.Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);

		GetPawn()->AddMovementInput(Direction, Value);
	}
}

void AUnreal_TP1PlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator Yaw(0.0f, Rotation.Yaw, 0.0f);

		const FVector Direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);

		GetPawn()->AddMovementInput(Direction, Value);
	}
}

void AUnreal_TP1PlayerController::Shoot()
{
	if (GetPawn()->GetClass()->ImplementsInterface(UShootingInterface::StaticClass()))
		IShootingInterface::Execute_Shoot(GetPawn());
}