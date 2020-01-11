// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidgetBase.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UMainMenu : public UMenuWidgetBase
{
	GENERATED_BODY()
	
	UMainMenu(const FObjectInitializer& ObjectInitializer);

protected:

	virtual bool Initialize() override;

private:


	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void QuitGame();

	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;
};
