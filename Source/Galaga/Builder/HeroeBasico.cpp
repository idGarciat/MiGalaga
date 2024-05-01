// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroeBasico.h"
#include "Heroe.h"

// Sets default values
AHeroeBasico::AHeroeBasico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHeroeBasico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroeBasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroeBasico::BuildHero(FVector StartLocation, FRotator StartRotation)
{
	Hero = GetWorld()->SpawnActor<AHeroe>(AHeroe::StaticClass(), StartLocation, StartRotation);
	Hero->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AHeroeBasico::BuildMesh()
{
	Hero->SetMesh(Mesh1);
}

void AHeroeBasico::BuildMaterial()
{
	Hero->SetMaterial(Material1);
}

void AHeroeBasico::BuildLife()
{
	Hero->SetLife(2000);
}

void AHeroeBasico::BuildSpeed()
{
	Hero->SetSpeed(100);
}

void AHeroeBasico::BuildDamage()
{
	Hero->SetDamage(15);
}

AHeroe* AHeroeBasico::GetHero()
{
	return Hero;
}
