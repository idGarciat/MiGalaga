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
    // Un ejemplo de c�mo declarar un bot�n
    UPROPERTY(meta = (BindWidget))
    class UButton* MyButton;

    // Funci�n para manejar el clic del bot�n
    UFUNCTION()
    void OnMyButtonClicked();
	
};
