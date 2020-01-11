// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AMovingBall::AMovingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if (!ensure(StaticMesh != nullptr))
		return;
	RootComponent = StaticMesh;
	StaticMesh->SetSimulatePhysics(true);*/

	
}

void AMovingBall::BallFireStart(UPrimitiveComponent* StaticMeshComp)
{
	FVector Impulse;
	float DeltaSec = GetWorld()->GetDeltaSeconds();
	Impulse.X = DeltaSec * ImpulseForce;
	Impulse.Y = DeltaSec * ImpulseForce;
	StaticMeshComp->AddImpulse(Impulse);
}

// Called when the game starts or when spawned
void AMovingBall::BeginPlay()
{
	Super::BeginPlay();
	//StaticMesh->SetSimulatePhysics(true);
	//BallFireStart();
	ImpulseForce = 500.f;

	
	//UE_LOG(LogTemp, Warning, TEXT(" Location: %s"), StartLocation.X, TEXT("  "), StartLocation.Y);
}

// Called every frame
void AMovingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

