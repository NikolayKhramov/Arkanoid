// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishMenu.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

UFinishMenu::UFinishMenu(const FObjectInitializer& ObjectInitializer) {

}



bool UFinishMenu::Initialize()
{
	bool is_succeed = Super::Initialize();
	if (!is_succeed)
		return false;

	PlayButton->OnClicked.AddDynamic(this, &UFinishMenu::StartGame);
	ExitButton->OnClicked.AddDynamic(this, &UFinishMenu::QuitGame);

	return true;
}

void UFinishMenu::StartGame()
{

	if (MenuInterface != nullptr) {
		MenuInterface->ContinuePlay();
	}
}

void UFinishMenu::QuitGame()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr))
		return;

	PlayerController->ConsoleCommand("Quit");

}

void UFinishMenu::SetUpText(bool Success)
{

	if (Success) {
		TextBlock1->SetText(FText::FromString("You are winner! Congrats!)"));
		TextBlockOnButton->SetText(FText::FromString("Play again"));
	}
	else {
		TextBlock1->SetText(FText::FromString("Do not worry its only game!"));
		TextBlockOnButton->SetText(FText::FromString("Try again"));
	}

}
