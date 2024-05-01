// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actores.h"
#include "CocoProtagonista.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ACocoProtagonista : public AActores
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;

	virtual void Transporte() override;
};
