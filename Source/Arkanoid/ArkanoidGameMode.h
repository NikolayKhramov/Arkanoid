// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameMode.generated.h"

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi)
class AArkanoidGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArkanoidGameMode(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
		int GetAmountOfBlocks();
	UFUNCTION(BlueprintCallable)
		void DecrementAmountOfBlocks();
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		int AmountOfBlocks;
	UPROPERTY(EditAnyWhere)
		TArray<AActor*> Blocks;

	TSubclassOf<AActor> BlockClass;
};



