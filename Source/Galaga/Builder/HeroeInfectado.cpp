// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroeInfectado.h"
#include "Heroe.h"

// Sets default values
AHeroeInfectado::AHeroeInfectado()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHeroeInfectado::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroeInfectado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroeInfectado::BuildHero(FVector StartLocation, FRotator StartRotation)
{
	Hero = GetWorld()->SpawnActor<AHeroe>(AHeroe::StaticClass(), StartLocation, StartRotation);
	Hero->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AHeroeInfectado::BuildMesh()
{
	Hero->SetMesh(Mesh1);
}

void AHeroeInfectado::BuildMaterial()
{
	Hero->SetMaterial(Material1);
}

void AHeroeInfectado::BuildLife()
{
	Hero->SetLife(2000);
}

void AHeroeInfectado::BuildSpeed()
{
	Hero->SetSpeed(100);
}

void AHeroeInfectado::BuildDamage()
{
	Hero->SetDamage(15);
}

AHeroe* AHeroeInfectado::GetHero()
{
	return Hero;
}

