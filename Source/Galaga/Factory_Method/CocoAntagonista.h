// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actores.h"
#include "CocoAntagonista.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ACocoAntagonista : public AActores
{
	GENERATED_BODY()


public:

	ACocoAntagonista();

	virtual void BeginPlay() override;

	virtual void Transporte() override;
	
};
