// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorDeActores.h"

// Sets default values
AGeneradorDeActores::AGeneradorDeActores()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeneradorDeActores::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneradorDeActores::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActores* AGeneradorDeActores::OrdenarActores(FString Categoria, FVector Posicion)
{

	AActores* Actor = CrearActores(Categoria, Posicion);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Creando %s"),*Actor->GetNombreActor()));
	//Start the concoct process

	Actor->Transporte();



	//Returns the created potion
	return Actor;
}
