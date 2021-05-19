// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "TimerManager.h"
#include "Unreal_TP1/Interfaces/ShootingInterface.h"
#include "Projectiles/BaseProjectile.h"
#include "BaseShip.generated.h"

UCLASS()
class UNREAL_TP1_API ABaseShip : public APawn, public IShootingInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ShipMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship Component", meta = (AllowPrivateAccess = "true"))
	UFloatingPawnMovement* ShipFloatingPawnMovement;

public:
	// Sets default values for this pawn's properties
	ABaseShip();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	bool ReadyToShoot = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float CoolDownDuration = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	TSubclassOf<class ABaseProjectile> ProjectileClass;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Category = "Shooting")
	void CoolDownShot();

	UFUNCTION(Category = "Shooting")
	void SetReadyToShootTrue();

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void SpawnProjectile();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Intefaces
	void Shoot_Implementation() override;
};