// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "InventoryActor.h"
#include "MiniNaveEnemigaLoca01.h"
#include "MiniNaveEnemigaLoca02.h"
#include "MiniNaveEnemigaLoca03.h"
#include "HierarchyActor.h"
#include "CapsulaVelocidad.h"
#include "CapsulaDisparo.h"
#include "GalagaGameMode.generated.h"

class ANaveEnemiga;
class AMiniNaveEnemigaCaza01;
class AMiniNaveEnemigaCaza02;
class AMiniNaveEnemigaEspia01;
class AMiniNaveEnemigaEspia02;
class AMiniNaveEnemigaNodriza01;
class AMiniNaveEnemigaNodriza02;


UCLASS(MinimalAPI)
class AGalagaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalagaGameMode();

	virtual void BeginPlay() override;

	ANaveEnemiga* NaveEnemiga01;
	AMiniNaveEnemigaCaza01* MiniNaveEnemigaCaza01;
	AMiniNaveEnemigaCaza02* MiniNaveEnemigaCaza02;
	AMiniNaveEnemigaEspia01* MiniNaveEnemigaEspia01;
	AMiniNaveEnemigaEspia02* MiniNaveEnemigaEspia02;
	AMiniNaveEnemigaNodriza01* MiniNaveEnemigaNodriza01;
	AMiniNaveEnemigaNodriza02* MiniNaveEnemigaNodriza02;
	

	AMiniNaveEnemigaLoca01* MiniNaveEnemigaLoca01;
	AMiniNaveEnemigaLoca02* MiniNaveEnemigaLoca02;
	AMiniNaveEnemigaLoca03* MiniNaveEnemigaLoca03;

	AHierarchyActor* HierarchyActor;

	AInventoryActor* InventoryActor;
	ACapsulaVelocidad* CapsulaVelocidad;
	ACapsulaDisparo* CapsulaDisparo;





};



