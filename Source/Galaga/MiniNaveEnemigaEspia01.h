// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaEspia.h"
#include "MiniNaveEnemigaEspia01.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AMiniNaveEnemigaEspia01 : public ANaveEnemigaEspia
{
	GENERATED_BODY()

	public:
		AMiniNaveEnemigaEspia01();
		virtual void BeginPlay() override;
		//virtual void Mover(float DeltaTime) override;
		virtual void Disparar(FVector DireccionDisparo) override;
		virtual void Disparo();

	
};
