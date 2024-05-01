// Fill out your copyright notice in the Description page of Project Settings.


#include "PepeAntagonista.h"

void APepeAntagonista::BeginPlay()
{
	Super::BeginPlay();

	NombreActor = "Pepe Malisimo";

}

void APepeAntagonista::Transporte()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Kill me pls")));

}
