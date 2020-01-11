// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface_.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface_ : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARKANOID_API IMenuInterface_
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void LoadMainMenu() = 0;
	virtual void LoadFinishMenu(bool Success) = 0;
	virtual void StartPlay() = 0;
	virtual void ContinuePlay() = 0;

};
