// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaLoca.h"
#include "RandomMovementComponent.h"
#include "MiniNaveEnemigaLoca01.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AMiniNaveEnemigaLoca01 : public ANaveEnemigaLoca
{
	GENERATED_BODY()

public:
	AMiniNaveEnemigaLoca01();

	UPROPERTY(EditAnywhere)
	URandomMovementComponent* MovimientoAleatorio;
	
};
