// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaProtagonistas.h"
#include "CocoProtagonista.h"
#include "PepeProtagonista.h"

AActores* AFabricaProtagonistas::CrearActores(FString ActoresSKU, FVector Ubicacion)
{
	//Select which potion to spawn depending on the passed string
	if (ActoresSKU.Equals("Coco Bueno")) {
		return GetWorld()->SpawnActor<ACocoProtagonista>(ACocoProtagonista::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	}
	else if (ActoresSKU.Equals("Pepe Bueno")) {
		return GetWorld()->SpawnActor<APepeProtagonista>(APepeProtagonista::StaticClass(), Ubicacion, FRotator::ZeroRotator);
	}
	else return nullptr; //Return null if the string isn't valid
}
