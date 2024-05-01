// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoAntagonista.h"

ACocoAntagonista::ACocoAntagonista()
{
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ActorMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));

	MeshActor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));


	MeshActor->SetStaticMesh(ActorMesh.Object);

}

void ACocoAntagonista::BeginPlay()
{
	Super::BeginPlay();

	NombreActor = "Coco Malisimo";
}

void ACocoAntagonista::Transporte()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Kill me pls")));

}
