// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoJambo.h"

// Sets default values
ACocoJambo::ACocoJambo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshCoco = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCoco"));
	RootComponent = MeshCoco;


}

// Called when the game starts or when spawned
void ACocoJambo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACocoJambo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ACocoJambo::Recibirdano()
{
	return this->Musicos->Recibirdano();
}

void ACocoJambo::Tanier()
{
	this->Musicos->Tanier();
}

void ACocoJambo::Pelear()
{
	this->Musicos->Pelear();
}

void ACocoJambo::Afinar()
{
	this->Musicos->Afinar();
}

void ACocoJambo::SetMesh()
{
	this->Musicos->SetMesh();
}

