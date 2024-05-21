// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroeFuturista.h"
#include "Heroe.h"

// Sets default values
AHeroeFuturista::AHeroeFuturista()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHeroeFuturista::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroeFuturista::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroeFuturista::BuildHero(FVector StartLocation, FRotator StartRotation)
{
	Hero = GetWorld()->SpawnActor<AHeroe>(AHeroe::StaticClass(), StartLocation, StartRotation);

	Hero->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);


}

void AHeroeFuturista::BuildMesh()
{
	Hero->SetMesh(Mesh1);
}

void AHeroeFuturista::BuildMaterial()
{
	Hero->SetMaterial(Material1);
}

void AHeroeFuturista::BuildLife()
{
	Hero->SetLife(2000);
}

void AHeroeFuturista::BuildSpeed()
{
	Hero->SetSpeed(100);
}

void AHeroeFuturista::BuildDamage()
{
	Hero->SetDamage(15);
}

AHeroe* AHeroeFuturista::GetHero()
{
	return Hero;
}

