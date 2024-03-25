// Copyright Epic Games, Inc. All Rights Reserved.

#include "GalagaGameMode.h"
#include "NaveEnemiga.h"
#include "MiniNaveEnemigaCaza01.h"
#include "MiniNaveEnemigaCaza02.h"
#include "MiniNaveEnemigaEspia01.h"
#include "MiniNaveEnemigaEspia02.h"
#include "MiniNaveEnemigaNodriza01.h"
#include "MiniNaveEnemigaNodriza02.h"
#include "GalagaPawn.h"

AGalagaGameMode::AGalagaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalagaPawn::StaticClass();
}

void AGalagaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
	FVector UbicacionNaveEnemiga01 = FVector(0,-400,215);
	FVector UbicacionMiniNaveEnemigaCaza01 = FVector(100,-400,215);
	FVector UbicacionMiniNaveEnemigaCaza02 = FVector(200,-400,215);
	FVector UbicacionMiniNaveEnemigaEspia01 = FVector(300,-400,215);
	FVector UbicacionMiniNaveEnemigaEspia02 = FVector(400,-400,215);
	FVector UbicacionMiniNaveEnemigaNodriza01 = FVector(500,-400,215);
	FVector UbicacionMiniNaveEnemigaNodriza02 = FVector(600,-400,215);


	//Spawn NaveEnemiga
	NaveEnemiga01=GetWorld()->SpawnActor<ANaveEnemiga>(UbicacionNaveEnemiga01, FRotator::ZeroRotator);
	MiniNaveEnemigaCaza01=GetWorld()->SpawnActor<AMiniNaveEnemigaCaza01>(UbicacionMiniNaveEnemigaCaza01, FRotator::ZeroRotator);
	MiniNaveEnemigaCaza02=GetWorld()->SpawnActor<AMiniNaveEnemigaCaza02>(UbicacionMiniNaveEnemigaCaza02, FRotator::ZeroRotator);
	MiniNaveEnemigaEspia01=GetWorld()->SpawnActor<AMiniNaveEnemigaEspia01>(UbicacionMiniNaveEnemigaEspia01, FRotator::ZeroRotator);
	MiniNaveEnemigaEspia02=GetWorld()->SpawnActor<AMiniNaveEnemigaEspia02>(UbicacionMiniNaveEnemigaEspia02, FRotator::ZeroRotator);
	MiniNaveEnemigaNodriza01=GetWorld()->SpawnActor<AMiniNaveEnemigaNodriza01>(UbicacionMiniNaveEnemigaNodriza01, FRotator::ZeroRotator);
	MiniNaveEnemigaNodriza02=GetWorld()->SpawnActor<AMiniNaveEnemigaNodriza02>(UbicacionMiniNaveEnemigaNodriza02, FRotator::ZeroRotator);


	//Spawn InventoryActor
	//InventoryActor=GetWorld()->SpawnActor<AInventoryActor>(FVector(0,0, 214), FRotator::ZeroRotator);
	//Spawn CapsulaVelocidad
	CapsulaVelocidad=GetWorld()->SpawnActor<ACapsulaVelocidad>(FVector(0,100, 214), FRotator::ZeroRotator);
	//Spawn CapsulaDisparo
	CapsulaDisparo=GetWorld()->SpawnActor<ACapsulaDisparo>(FVector(0,200, 214), FRotator::ZeroRotator);

	//Spawn MiniNaveEnemigaLoca01
	FVector UbicacionMiniNaveEnemigaLoca01 = FVector(700,-400,215);
	MiniNaveEnemigaLoca01=GetWorld()->SpawnActor<AMiniNaveEnemigaLoca01>(UbicacionMiniNaveEnemigaLoca01, FRotator::ZeroRotator);

	//Spawn MiniNaveEnemigaLoca02
	FVector UbicacionMiniNaveEnemigaLoca02 = FVector(800,-400,215);
	MiniNaveEnemigaLoca02=GetWorld()->SpawnActor<AMiniNaveEnemigaLoca02>(UbicacionMiniNaveEnemigaLoca02, FRotator::ZeroRotator);

	FVector UbicacionMiniNaveEnemigaLoca03 = FVector(900, -400, 215);
	MiniNaveEnemigaLoca03 = GetWorld()->SpawnActor<AMiniNaveEnemigaLoca03>(UbicacionMiniNaveEnemigaLoca03, FRotator::ZeroRotator);

	FVector UbicacionHierarchyActor = FVector(1000, -400, 215);
	HierarchyActor = GetWorld()->SpawnActor<AHierarchyActor>(UbicacionHierarchyActor, FRotator::ZeroRotator);
}

