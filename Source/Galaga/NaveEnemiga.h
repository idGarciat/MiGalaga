// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ANaveEnemiga : public ANave
{
	GENERATED_BODY()


public:
	ANaveEnemiga();

	virtual void Tick(float DeltaTime) override;

	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	virtual void Morir();
	virtual void Colisionar();





	
};
