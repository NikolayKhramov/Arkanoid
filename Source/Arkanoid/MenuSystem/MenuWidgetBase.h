// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface_.h"
#include "MenuWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UMenuWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UFUNCTION()
		void SetUp();
	UFUNCTION()
		void Teardown();
	

	void SetMenuInterface(IMenuInterface_* MenuInterface);

protected:
	IMenuInterface_* MenuInterface;

	virtual bool Initialize() override;
};
