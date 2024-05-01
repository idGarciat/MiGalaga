// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreadorHeroes.h"
#include "BioIngeniero.generated.h"

UCLASS()
class GALAGA_API ABioIngeniero : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABioIngeniero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ICreadorHeroes* CreadorHeroes;

public:

	void SetCreador(ICreadorHeroes* Creador);

	void CrearHeroe(FVector StartLocation, FRotator StartRotation);

	class AHeroe* GetHero();

};
