// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "PlayerIcon.h"

AMyPlayerController::AMyPlayerController()
{

	//bShowMouseCursor = true;

	//bEnableClickEvents = true;

	//DefaultMouseCursor = EMouseCursor::Default;

	//bEnableMouseOverEvents = true;

	//static ConstructorHelpers::FClassFinder<UPlayerIcon> WidgetClass(TEXT("Class'/Script/Galaga.PlayerIcon'"));
	//if (WidgetClass.Succeeded())
	//{
	//	MyPlayerIcon = WidgetClass.Class;
	//}

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	bEnableClickEvents = true;

	DefaultMouseCursor = EMouseCursor::Default;

	bEnableMouseOverEvents = true;

	//if (MyPlayerIcon)
	//{
	//	// Crear una instancia del widget y agregarlo al viewport
	//	MyWidgetInstance = CreateWidget<UPlayerIcon>(this, MyPlayerIcon);
	//	if (MyWidgetInstance)
	//	{
	//		MyWidgetInstance->AddToViewport();
	//	}
	//}
}
