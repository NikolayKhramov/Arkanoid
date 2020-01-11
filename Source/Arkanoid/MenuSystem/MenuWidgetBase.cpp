// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidgetBase.h"
#include "Engine/Engine.h"

void UMenuWidgetBase::SetUp()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;


	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr))
		return;

	this->bIsFocusable = true;

	FInputModeUIOnly InputData;
	InputData.SetWidgetToFocus(this->TakeWidget());
	InputData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputData);
	PlayerController->bShowMouseCursor = true;
}


void UMenuWidgetBase::Teardown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))
		return;


	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr))
		return;

	this->bIsFocusable = false;

	FInputModeGameOnly InputData;


	PlayerController->SetInputMode(InputData);
	PlayerController->bShowMouseCursor = false;
}



void UMenuWidgetBase::SetMenuInterface(IMenuInterface_* MenuInterface) {

	this->MenuInterface = MenuInterface;

}

bool UMenuWidgetBase::Initialize()
{
	bool is_succeed = Super::Initialize();
	if (!is_succeed)
		return false;


	return true;
}
