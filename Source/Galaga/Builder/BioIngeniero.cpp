// Fill out your copyright notice in the Description page of Project Settings.


#include "BioIngeniero.h"
#include "Heroe.h"

// Sets default values
ABioIngeniero::ABioIngeniero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABioIngeniero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABioIngeniero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABioIngeniero::SetCreador(ICreadorHeroes* Creador)
{
	CreadorHeroes = Cast<ICreadorHeroes>(Creador);
}

void ABioIngeniero::CrearHeroe(FVector StartLocation, FRotator StartRotation)
{
	CreadorHeroes->BuildHero(StartLocation, StartRotation);
	CreadorHeroes->BuildMesh();
	CreadorHeroes->BuildMaterial();
	CreadorHeroes->BuildLife();
	CreadorHeroes->BuildSpeed();
	CreadorHeroes->BuildDamage();

}

AHeroe* ABioIngeniero::GetHero()
{
	if (CreadorHeroes != nullptr)
	{
		return CreadorHeroes->GetHero();
	}
	return nullptr;
}

