// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaLoca.h"
#include "OrbitingMovementComponent.h"
#include "MiniNaveEnemigaLoca02.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AMiniNaveEnemigaLoca02 : public ANaveEnemigaLoca
{
	GENERATED_BODY()
	
public:
	AMiniNaveEnemigaLoca02();
	
	UPROPERTY(EditAnywhere)
	UOrbitingMovementComponent* OrbitingMovement;


};
