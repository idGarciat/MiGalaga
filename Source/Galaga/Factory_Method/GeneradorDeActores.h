// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actores.h"
#include "GeneradorDeActores.generated.h"

UCLASS()
class GALAGA_API AGeneradorDeActores : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneradorDeActores();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual AActores* CrearActores(FString ActoresSKU, FVector Ubicacion) PURE_VIRTUAL(AGeneradorDeActores::CrearActores, return nullptr;);

	AActores* OrdenarActores(FString Categoria, FVector Posicion);


};
