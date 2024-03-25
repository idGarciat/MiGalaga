// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaLoca.h"
#include "MiniNaveEnemigaLoca03.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API AMiniNaveEnemigaLoca03 : public ANaveEnemigaLoca
{
	GENERATED_BODY()
public:

	AMiniNaveEnemigaLoca03();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


};
