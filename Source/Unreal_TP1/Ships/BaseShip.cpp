// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseShip.h"

// Sets default values
ABaseShip::ABaseShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;

	ShipFloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
}

// Called when the game starts or when spawned
void ABaseShip::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseShip::SetReadyToShootTrue()
{
	ReadyToShoot = true;
}

void ABaseShip::SpawnProjectile()
{
	if (ReadyToShoot)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParameters.Instigator = this;

		ABaseProjectile* SpawnedActor = GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, GetActorLocation(), GetActorRotation(), SpawnParameters);
		MoveIgnoreActorAdd(SpawnedActor);

		ReadyToShoot = false;
		CoolDownShot();
	}
}

// Called every frame
void ABaseShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseShip::Shoot_Implementation()
{
	SpawnProjectile();
}

void ABaseShip::CoolDownShot()
{
	FTimerHandle UnusedHandle;

	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABaseShip::SetReadyToShootTrue, CoolDownDuration);
}