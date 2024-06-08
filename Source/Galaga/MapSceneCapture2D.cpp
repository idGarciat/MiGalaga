// Fill out your copyright notice in the Description page of Project Settings.


#include "MapSceneCapture2D.h"
#include "Components/SceneCaptureComponent2D.h"


AMapSceneCapture2D::AMapSceneCapture2D()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//CreateAbstractDefaultSubobject<USceneCaptureComponent2D>(TEXT("CaptureComponent2D"));

	SetActorRotation(FRotator(-90.0f, 0.0f, 0.0f));


	USceneCaptureComponent2D* CaptureComponent = GetCaptureComponent2D();

	if (CaptureComponent)
	{
		// Inicializar el ancho ortogr�fico a un valor por defecto, si es necesario
		CaptureComponent->ProjectionType = ECameraProjectionMode::Orthographic;
		CaptureComponent->OrthoWidth = 4000; // Cambia este valor seg�n tus necesidades
	}

}

void AMapSceneCapture2D::BeginPlay()
{
	Super::BeginPlay();

	

}


