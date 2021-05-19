// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Unreal_TP1/Ships/BaseShip.h"
#include "BasePowerUp.generated.h"

UENUM(BlueprintType, DisplayName = "Power Up Type")
enum PowerUpType
{
	FasterShotCoolDown UMETA(DisplayName = "Faster Shot Cool Down")
};

UCLASS()
class UNREAL_TP1_API ABasePowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePowerUp();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EffectDuration = 5.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<PowerUpType> Type = PowerUpType::FasterShotCoolDown;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};