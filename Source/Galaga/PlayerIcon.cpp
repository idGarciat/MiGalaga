// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIcon.h"
#include "Components/Button.h"

void UPlayerIcon::NativeConstruct()
{
    Super::NativeConstruct();

    // Vincular la funci�n de clic del bot�n
    if (MyButton)
    {
        MyButton->OnClicked.AddDynamic(this, &UPlayerIcon::OnMyButtonClicked);
    }

}

void UPlayerIcon::OnMyButtonClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("�Bot�n clickeado!"));

}
