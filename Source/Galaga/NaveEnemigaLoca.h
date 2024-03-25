// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaLoca.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ANaveEnemigaLoca : public ANaveEnemiga
{
	GENERATED_BODY()
	
public:
	virtual void Mover(float DeltaTime) override;

};
