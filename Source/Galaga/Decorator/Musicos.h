// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Musicos.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMusicos : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_API IMusicos
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual float Recibirdano() = 0;
	virtual void Tanier() = 0;
	virtual void Pelear() = 0;
	virtual void Afinar() = 0;
	virtual void SetMesh() = 0;
	virtual TArray<AActor*> GetActorsInSphere() = 0;

};
