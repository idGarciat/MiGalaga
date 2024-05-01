// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoProtagonista.h"

void ACocoProtagonista::BeginPlay()
{
	Super::BeginPlay();

	NombreActor = "Coco Buenisimo";
}

void ACocoProtagonista::Transporte()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Kill me pls")));

}
