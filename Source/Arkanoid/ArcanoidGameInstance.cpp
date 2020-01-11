// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcanoidGameInstance.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/FinishMenu.h"

UArcanoidGameInstance::UArcanoidGameInstance(const FObjectInitializer& ObjectInitializer) {

	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/Arkanoid/Blueprints/WBP_MainMenu"));
	if (!ensure(MainMenuBPClass.Class != nullptr))
		return;

	MainMenuClass = MainMenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> FinishMenuBPClass(TEXT("/Game/Arkanoid/Blueprints/WBP_FinishMenu"));
	if (!ensure(FinishMenuBPClass.Class != nullptr))
		return;

	FinishMenuClass = FinishMenuBPClass.Class;

}

void UArcanoidGameInstance::LoadMainMenu() {

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr))
		return;

	
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;
	World->ServerTravel("/Game/Arkanoid/Maps/ArkanoidStartLevel");
	

}

void UArcanoidGameInstance::LoadMainMenuWidget()
{
	if (!ensure(MainMenuClass != nullptr))
		return;

	MainMenu = CreateWidget<UMainMenu>(this, MainMenuClass);
	if (!ensure(MainMenu != nullptr))
		return;

	MainMenu->SetUp();

	MainMenu->SetMenuInterface(this);

}

void UArcanoidGameInstance::LoadFinishMenuWidget()
{

	if (!ensure(FinishMenuClass != nullptr))
		return;

	FinishMenu = CreateWidget<UFinishMenu>(this, FinishMenuClass);
	if (!ensure(MainMenu != nullptr))
		return;

	FinishMenu->SetUp();

	FinishMenu->SetMenuInterface(this);

	FinishMenu->SetUpText(Success);

}

void UArcanoidGameInstance::SetSuccess(bool success)
{
	Success = success;
}


void UArcanoidGameInstance::LoadFinishMenu(bool Success) {

	this-> Success = Success;
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;

	World->ServerTravel("/Game/Arkanoid/Maps/ArkanoidFinishLevel");



 }


void UArcanoidGameInstance::StartPlay() {

	if (MainMenu != nullptr) {
		MainMenu->Teardown();

		UWorld* World = GetWorld();
		if (!ensure(World != nullptr))
			return;

		World->ServerTravel("/Game/Arkanoid/Maps/ArkanoidMainLevel");
	}

}

void UArcanoidGameInstance::ContinuePlay()
{
	if (FinishMenu != nullptr) {
		FinishMenu->Teardown();

		UWorld* World = GetWorld();
		if (!ensure(World != nullptr))
			return;

		World->ServerTravel("/Game/Arkanoid/Maps/ArkanoidMainLevel");
	}
}
