// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actores.h"
#include "PepeAntagonista.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API APepeAntagonista : public AActores
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Transporte() override;

	
};
