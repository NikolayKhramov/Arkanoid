// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface_.h"
#include "ArcanoidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UArcanoidGameInstance : public UGameInstance, public IMenuInterface_
{
	GENERATED_BODY()

public:
	UArcanoidGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void LoadMainMenu() override;
	virtual void LoadFinishMenu(bool Success) override;
	virtual void StartPlay() override;
	virtual void ContinuePlay() override;


	UFUNCTION(BlueprintCallable)
		void LoadMainMenuWidget();
	UFUNCTION(BlueprintCallable)
		void LoadFinishMenuWidget();

	void SetSuccess(bool success);

protected:


private:
	TSubclassOf<UUserWidget> MainMenuClass;
	class UMainMenu* MainMenu;
	TSubclassOf<UUserWidget> FinishMenuClass;
	class UFinishMenu* FinishMenu;

	bool Success;
};
