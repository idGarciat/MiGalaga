// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneradorDeActores.h"
#include "FabricaAntagonistas.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AFabricaAntagonistas : public AGeneradorDeActores
{
	GENERATED_BODY()
public:
	virtual AActores* CrearActores(FString ActoresSKU, FVector Ubicacion) override;

	
};
