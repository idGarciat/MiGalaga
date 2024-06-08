// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

protected:

	virtual void BeginPlay() override;

	// Clase del widget
	TSubclassOf<class UPlayerIcon> MyPlayerIcon;

	// Instancia del widget
	UPlayerIcon* MyWidgetInstance;
};
