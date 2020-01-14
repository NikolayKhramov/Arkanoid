// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingBall.generated.h"

UCLASS()
class ARKANOID_API AMovingBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingBall();

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (MakeEditWidget = true))
		FVector StartLocation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ImpulseForce;
	UFUNCTION(BlueprintCallable)
		void BallFireStart(class UPrimitiveComponent* StaticMeshComp);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UFUNCTION()
		void OnTimerEnableCollision();

	bool bPauseHit;

	FVector Velocity;

	float DegreeToRotate;

	FTimerHandle LoopTimer;
};
