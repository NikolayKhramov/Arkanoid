// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockToDestroy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MovingBall.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "ArkanoidGameMode.h"
#include "ArcanoidGameInstance.h"


// Sets default values
ABlockToDestroy::ABlockToDestroy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Volume"));
	if (!ensure(TriggerVolume != nullptr))
		return;

	RootComponent = TriggerVolume;
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ABlockToDestroy::OnOverlapBegin);


	//Can be set in the editor(made for any variaty of difficulty)
	//1 by default
	AmountHitsToDestroy = 1;
	
}


void ABlockToDestroy::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult & SweepResult) 
{
	//cast to ball
	AMovingBall* MovingBall = Cast<AMovingBall>(OtherActor);

	//if cast to ball succeed
	if (MovingBall != nullptr) {

		//decrement variable on each ball-touch if == 0 then destroy block
		--AmountHitsToDestroy;
		if (AmountHitsToDestroy < 1) {

			GetWorldTimerManager().SetTimer(LoopTimer, this, &ABlockToDestroy::OnTimerDestroyActor, 0.1f, false);
		}
	}
}



// Called when the game starts or when spawned
void ABlockToDestroy::BeginPlay()
{
	Super::BeginPlay();
	



}

// Called every frame
void ABlockToDestroy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockToDestroy::OnTimerDestroyActor()
{

	Destroy();
	
	AArkanoidGameMode* GameMode = Cast< AArkanoidGameMode>(GetWorld()->GetAuthGameMode());
	if (!ensure(GameMode != nullptr)) return;
	GameMode->DecrementAmountOfBlocks();
	if (GameMode->GetAmountOfBlocks() == 0) {
		LoadSuccessLevel();
		//GetWorldTimerManager().SetTimer(LoopTimer2, this, &ABlockToDestroy::LoadSuccessLevel, 1.f, false);
			
	}
	
	
}

void ABlockToDestroy::LoadSuccessLevel()
{
	UArcanoidGameInstance* GameInstance = Cast<UArcanoidGameInstance>(GetGameInstance());
	if (GameInstance != nullptr) {
		//load finish menu with true success because all blocks were destroyed
		GameInstance->LoadFinishMenu(true);
	}
}

