// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerIcon.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API UPlayerIcon : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

protected:
    // Un ejemplo de cómo declarar un botón
    UPROPERTY(meta = (BindWidget))
    class UButton* MyButton;

    // Función para manejar el clic del botón
    UFUNCTION()
    void OnMyButtonClicked();
	
};
