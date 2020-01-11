
// Fill out your copyright notice in the Description page of Project Settings.

#include "LoseTrigger.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PlayerController.h"
#include "MovingBall.h"
#include "ArcanoidGameInstance.h"

// Sets default values
ALoseTrigger::ALoseTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Volume"));
	if (!ensure(TriggerVolume != nullptr))
		return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ALoseTrigger::OnOverlapBegin);
}

void ALoseTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, 
									UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									const FHitResult & SweepResult) 
{
	AMovingBall* MovingBall = Cast<AMovingBall>(OtherActor);
	if (MovingBall != nullptr) {

		MovingBall->Destroy();

		UArcanoidGameInstance* GameInstance = Cast<UArcanoidGameInstance>(GetGameInstance());
		if (GameInstance != nullptr) {
			//load finish menu with false success because ball wasnt catched
			GameInstance->LoadFinishMenu(false);
		}
		/*UWorld* World = GetWorld();
		if (!ensure(World != nullptr))
			return;

		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (!ensure(PlayerController != nullptr))
			return;

		PlayerController->ConsoleCommand("Quit");*/
		
	}

}

// Called when the game starts or when spawned
void ALoseTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoseTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

