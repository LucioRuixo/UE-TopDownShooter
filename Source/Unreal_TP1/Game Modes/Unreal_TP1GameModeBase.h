// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Unreal_TP1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_TP1_API AUnreal_TP1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Game Flow")
	void EndGame();

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Game Flow")
	void OnStartGame();

	UFUNCTION(BlueprintImplementableEvent, Category = "Game Flow")
	void OnEndGame();
};