// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../GalagaProjectile.h"
#include "../GalagaPawn.h"
#include "DesviarProyectiles.generated.h"

UCLASS()
class GALAGA_API ADesviarProyectiles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADesviarProyectiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void DesviacionProyectiles(AGalagaProjectile* MyProyectile);

	AGalagaPawn* MyPawn;
};
