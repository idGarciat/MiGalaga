// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Campeones.h"
#include "Tryndamere.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ATryndamere : public ACampeones
{
	GENERATED_BODY()

public:
	ATryndamere();
	virtual void BeginPlay() override;

	virtual void Passive() override;
	virtual void Ability1() override;
	virtual void Ability2() override;
	virtual void Ability3() override;
	virtual void Ability4() override;

	
};
