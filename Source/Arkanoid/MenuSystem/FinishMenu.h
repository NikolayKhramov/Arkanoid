// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidgetBase.h"
#include "FinishMenu.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UFinishMenu : public UMenuWidgetBase
{
	GENERATED_BODY()
public:

	UFinishMenu(const FObjectInitializer& ObjectInitializer);

	void SetUpText(bool Success);

protected:

	virtual bool Initialize() override;

private:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlock1;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlockOnButton;

	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void QuitGame();

	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;

};
