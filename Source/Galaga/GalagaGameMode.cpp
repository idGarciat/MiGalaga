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
#include "MyPlayerController.h"
#include "Factory_Method/FactoryMethod_Main.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "Builder/Builder_Main.h"

AGalagaGameMode::AGalagaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalagaPawn::StaticClass();

	PlayerControllerClass = AMyPlayerController::StaticClass();

}

void AGalagaGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Spawn Jugadores

	//Cast<APlayerController>(UGameplayStatics::CreatePlayer(GetWorld(), 1));


	//class AGalagaPawn* Jugador2EnMundo = GetWorld()->SpawnActor<AGalagaPawn>(AGalagaPawn::StaticClass(), FVector(-1050,10,215), FRotator::ZeroRotator);
	//Jugador2EnMundo->AutoPossessPlayer = EAutoReceiveInput::Player1;



	FVector UbicacionNaveEnemiga01 = FVector(0,-400,215);
	FVector UbicacionMiniNaveEnemigaCaza01 = FVector(100,-400,215);
	FVector UbicacionMiniNaveEnemigaCaza02 = FVector(100,-700,215);
	FVector UbicacionMiniNaveEnemigaEspia01 = FVector(100,-900,215);
	FVector UbicacionMiniNaveEnemigaEspia02 = FVector(100,-1100,215);
	FVector UbicacionMiniNaveEnemigaNodriza01 = FVector(100,-1300,215);
	FVector UbicacionMiniNaveEnemigaNodriza02 = FVector(100,-1500,215);


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

	//Spawn FactoryMethod_Main
	//AFactoryMethod_Main* FactoryMethod_Main = GetWorld()->SpawnActor<AFactoryMethod_Main>(AFactoryMethod_Main::StaticClass());

	//Spawn Builder_Main
	//ABuilder_Main* Builder_Main = GetWorld()->SpawnActor<ABuilder_Main>(ABuilder_Main::StaticClass());

}

