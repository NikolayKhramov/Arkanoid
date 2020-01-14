// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "TimerManager.h"

// Sets default values
AMovingBall::AMovingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if (!ensure(StaticMesh != nullptr))
		return;
	RootComponent = StaticMesh;*/
	
	Speed = 20.f;
	DegreeToRotate = 0.f;
	bPauseHit = false;
}

void AMovingBall::BallFireStart(UPrimitiveComponent* StaticMeshComp)
{
	
}

// Called when the game starts or when spawned
void AMovingBall::BeginPlay()
{
	Super::BeginPlay();

	

	
	//UE_LOG(LogTemp, Warning, TEXT(" Location: %s"), StartLocation.X, TEXT("  "), StartLocation.Y);
}

// Called every frame
void AMovingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Velocity = GetActorForwardVector() * Speed;

	FVector Translation = Velocity * DeltaTime * 25;

	FQuat RotationDelta(GetActorUpVector(), DegreeToRotate);

	RotationDelta.RotateVector(Translation);

	AddActorWorldRotation(RotationDelta);
	FHitResult HitResult;
	AddActorWorldOffset(Translation, true, &HitResult);

	if (HitResult.IsValidBlockingHit() && !bPauseHit) {
		FVector_NetQuantizeNormal Normal = HitResult.ImpactNormal;
		float xball = GetActorForwardVector().X, yball = GetActorForwardVector().Y;

		float cos_ = (xball * Normal.X + yball * Normal.Y) / ((FMath::Sqrt(xball* xball + yball * yball)) * (FMath::Sqrt(Normal.X * Normal.X + Normal.Y * Normal.Y)));

		if(cos>=0)
			DegreeToRotate = 1.9 * FMath::Acos(cos_);
		else if(cos<0)
			DegreeToRotate = -(1.9 * FMath::Acos(cos_));

		SetActorEnableCollision(false);
		GetWorldTimerManager().SetTimer(LoopTimer, this, &AMovingBall::OnTimerEnableCollision, 0.1f, false);
	}
	else {
		DegreeToRotate = 0.f;
	}
}

void AMovingBall::OnTimerEnableCollision()
{
	SetActorEnableCollision(true);
	
}

