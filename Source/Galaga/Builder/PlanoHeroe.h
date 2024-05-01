// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlanoHeroe.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlanoHeroe : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_API IPlanoHeroe
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void SetMesh(class UStaticMesh* MeshHero) = 0;
	virtual void SetMaterial(class UMaterial* Material) = 0;
	virtual void SetLife(int Life) = 0;
	virtual void SetSpeed(float Speed) = 0;
	virtual void SetDamage(int Damage) = 0;
};
