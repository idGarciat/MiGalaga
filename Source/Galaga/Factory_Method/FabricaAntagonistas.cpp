// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaAntagonistas.h"
#include "CocoAntagonista.h"
#include "PepeAntagonista.h"

AActores* AFabricaAntagonistas::CrearActores(FString ActoresSKU, FVector Ubicacion)
{
	//Select which potion to spawn depending on the passed string
	if (ActoresSKU.Equals("Coco Malo")) {
		return GetWorld()->SpawnActor<ACocoAntagonista>(ACocoAntagonista::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	}
	else if (ActoresSKU.Equals("Pepe Malo")) {
		return GetWorld()->SpawnActor<APepeAntagonista>(APepeAntagonista::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	}
	else return nullptr; //Return null if the string isn't valid
}
