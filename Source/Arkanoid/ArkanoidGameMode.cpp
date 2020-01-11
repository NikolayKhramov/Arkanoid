// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ArkanoidGameMode.h"
#include "ArkanoidPlayerController.h"
#include "ArkanoidPawn.h"
#include "GameFramework/PlayerController.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"



AArkanoidGameMode::AArkanoidGameMode(const FObjectInitializer& ObjectInitializer)
{
	
	// no pawn by default
	DefaultPawnClass = AArkanoidPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AArkanoidPlayerController::StaticClass();


	ConstructorHelpers::FClassFinder<AActor> BlockBPClass(TEXT("/Game/Arkanoid/Blueprints/BP_BlockToDestroy"));
	if (!ensure(BlockBPClass.Class != nullptr))
		return;
	BlockClass = BlockBPClass.Class;

}

int AArkanoidGameMode::GetAmountOfBlocks()
{
	return AmountOfBlocks;
}

void AArkanoidGameMode::DecrementAmountOfBlocks()
{
	if (AmountOfBlocks > 0)
		AmountOfBlocks--;
	
}


void AArkanoidGameMode::BeginPlay()
{
	Super::BeginPlay();

	
	if (BlockClass != nullptr) {
		UGameplayStatics::GetAllActorsOfClass(this, BlockClass, Blocks);
		AmountOfBlocks = Blocks.Num();
	}

}
