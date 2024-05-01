// Fill out your copyright notice in the Description page of Project Settings.


#include "FactoryMethod_Main.h"
#include "FabricaAntagonistas.h"
#include "FabricaProtagonistas.h"


// Sets default values
AFactoryMethod_Main::AFactoryMethod_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AFactoryMethod_Main::BeginPlay()
{
	Super::BeginPlay();


	AGeneradorDeActores* FabricaAntagonistas = GetWorld()->SpawnActor<AFabricaAntagonistas>(AFabricaAntagonistas::StaticClass());
	AGeneradorDeActores* FabricaProtagonistas = GetWorld()->SpawnActor<AFabricaProtagonistas>(AFabricaProtagonistas::StaticClass());

	AActores* Actores = FabricaAntagonistas->OrdenarActores("Coco Malo", FVector(50, 50, 50));


	
}

// Called every frame
void AFactoryMethod_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

