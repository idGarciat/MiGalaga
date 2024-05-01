// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder_Main.h"
#include "Heroe.h"
#include "BioIngeniero.h"
#include "HeroeBasico.h"
#include "HeroeInfectado.h"
#include "HeroeFuturista.h"

// Sets default values
ABuilder_Main::ABuilder_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilder_Main::BeginPlay()
{
	Super::BeginPlay();

	HeroeBasico = GetWorld()->SpawnActor<AHeroeBasico>(AHeroeBasico::StaticClass());
	HeroeFuturista = GetWorld()->SpawnActor<AHeroeFuturista>(AHeroeFuturista::StaticClass());
	HeroeInfectado = GetWorld()->SpawnActor<AHeroeInfectado>(AHeroeInfectado::StaticClass());

	BioIngeniero = GetWorld()->SpawnActor<ABioIngeniero>(ABioIngeniero::StaticClass());


	BioIngeniero->SetCreador(HeroeBasico);

	BioIngeniero->CrearHeroe(FVector(0, 0, 400), FRotator(0, 0, 0));


	BioIngeniero->SetCreador(HeroeFuturista);

	BioIngeniero->CrearHeroe(FVector(500, 0, 400), FRotator(0, 0, 0));

	BioIngeniero->SetCreador(HeroeInfectado);

	BioIngeniero->CrearHeroe(FVector(1000, 0, 400), FRotator(0, 0, 0));


	//AHeroe* Heroe = BioIngeniero->GetHero();
	//Heroe->HeroCharacteristics();
	
	
}

// Called every frame
void ABuilder_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

