// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Engine/Engine.h"


UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer) {



}




bool UMainMenu::Initialize() {
	bool is_succeed = Super::Initialize();
	if (!is_succeed)
		return false;

	PlayButton->OnClicked.AddDynamic(this, &UMainMenu::StartGame);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);

	return true;
}

void UMainMenu::StartGame()
{
	if (MenuInterface != nullptr) {
		MenuInterface->StartPlay();
	}
}

void UMainMenu::QuitGame()
{

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr))
		return;

	PlayerController->ConsoleCommand("Quit");
}
