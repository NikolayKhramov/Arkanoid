// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockToDestroy.generated.h"

UCLASS()
class ARKANOID_API ABlockToDestroy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockToDestroy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AmountHitsToDestroy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnTimerDestroyActor();

		void LoadSuccessLevel();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* TriggerVolume;

	UPROPERTY(EditAnyWhere)
		TArray<AActor*> Blocks;

	TSubclassOf<AActor> BlockClass;

	FTimerHandle LoopTimer;
	FTimerHandle LoopTimer2;

};

