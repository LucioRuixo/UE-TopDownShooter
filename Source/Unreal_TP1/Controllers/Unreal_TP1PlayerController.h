// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Unreal_TP1/Interfaces/ShootingInterface.h"
#include "Unreal_TP1PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_TP1_API AUnreal_TP1PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Shoot();
};