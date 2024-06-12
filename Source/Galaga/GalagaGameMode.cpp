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
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "Factory_Method/FactoryMethod_Main.h"
#include "Builder/Builder_Main.h"
#include "Decorator/Decorator_Main.h"
#include "MapSceneCapture2D.h"

#include "Command/ComenzarAtaqueCommand.h"
#include "Command/DetenerAtaqueCommand.h"
#include "Command/NaveCommand.h"
#include "Command/ControlCommand.h"

AGalagaGameMode::AGalagaGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our character class
	PlayerControllerClass = AMyPlayerController::StaticClass();

	DefaultPawnClass = AGalagaPawn::StaticClass();



	//static ConstructorHelpers::FClassFinder<APawn>FirstPlayerPawnBPClass(TEXT("Class'/Script/Galaga.GalagaPawn'"));
	//if (FirstPlayerPawnBPClass.Class != nullptr)
	//{
	//	FirstPlayerPawnClass = AGalagaPawn::StaticClass();
	//	FirstPlayerControllerClass = AMyPlayerController::StaticClass();
	//}

	//// Establecer la clase del pawn para el segundo jugador
	//static ConstructorHelpers::FClassFinder<APawn> SecondPlayerPawnBPClass(TEXT("Class'/Script/Galaga.GalagaPawn'"));
	//if (SecondPlayerPawnBPClass.Class != nullptr)
	//{
	//	SecondPlayerPawnClass = AGalagaPawn::StaticClass();
	//	SecondPlayerControllerClass = AMyPlayerController::StaticClass();
	//}

}

void AGalagaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Forma de spawn de jugador
	{

	////Spawn Jugadores
	//APlayerController* PlayerController2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	//if (!PlayerController2)
	//{
	//	PlayerController2 = UGameplayStatics::CreatePlayer(GetWorld(), 1, true);
	//}

	//// Spawnear el segundo pawn y poseerlo con el segundo PlayerController
	//if (PlayerController2)
	//{
	//	// Definir la ubicación y rotación para el segundo pawn
	//	FVector SpawnLocation = FVector(500, 500, 300); // Ubicación de ejemplo
	//	FRotator SpawnRotation = FRotator::ZeroRotator;

	//	//Spawnear el pawn
	//	AGalagaPawn* SecondPawn = GetWorld()->SpawnActor<AGalagaPawn>(PawnClass, SpawnLocation, SpawnRotation);
	//	if (SecondPawn)
	//	{
	//		PlayerController2->Possess(SecondPawn);
	//	}
	//}
	}
	
	//Problema con el controlador de jugador
	{

		//Crear el primer jugador (por defecto)
		//APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		//if (!PlayerController1)
		//{
		//		PlayerController1 = UGameplayStatics::CreatePlayer(GetWorld(), 0, true);

		//}

		////// Crear el segundo jugador
		////APlayerController* PlayerController2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
		////if (!PlayerController2)
		////{
		////	PlayerController2 = UGameplayStatics::CreatePlayer(GetWorld(), 1, true);
		////}

		//Spawnear el primer pawn
		//if (PlayerController1 && FirstPlayerPawnClass)
		//{
		//	FVector SpawnLocation1 = FVector(-1200, -200, 215); // Ubicación de ejemplo para el primer pawn
		//	FRotator SpawnRotation1 = FRotator::ZeroRotator;

		//	AGalagaPawn* FirstPawn = GetWorld()->SpawnActor<AGalagaPawn>(FirstPlayerPawnClass, SpawnLocation1, SpawnRotation1);

			//if (FirstPawn)
			//{
			//	PlayerController1->Possess(FirstPawn);
			//	PlayerController1->SetInputMode(FInputModeGameAndUI());

			//}
		//}

		//// Spawnear el segundo pawn
		//if (PlayerController2 && SecondPlayerPawnClass)
		//{
		//	FVector SpawnLocation2 = FVector(-1200, 0, 215); // Ubicación de ejemplo para el segundo pawn
		//	FRotator SpawnRotation2 = FRotator::ZeroRotator;

		//	AGalagaPawn* SecondPawn = GetWorld()->SpawnActor<AGalagaPawn>(SecondPlayerPawnClass, SpawnLocation2, SpawnRotation2);
		//	if (SecondPawn)
		//	{
		//		PlayerController2->Possess(SecondPawn);
		//		PlayerController2->SetInputMode(FInputModeGameAndUI());
		//		PlayerController1->bShowMouseCursor = true;


		//	}
		//}
	}

	//Spawn de naves
	{
		FVector UbicacionNaveEnemiga01 = FVector(0, -400, 215);
		FVector UbicacionMiniNaveEnemigaCaza01 = FVector(100, -400, 215);
		FVector UbicacionMiniNaveEnemigaCaza02 = FVector(100, -700, 215);
		FVector UbicacionMiniNaveEnemigaEspia01 = FVector(100, -900, 215);
		FVector UbicacionMiniNaveEnemigaEspia02 = FVector(100, -1100, 215);
		FVector UbicacionMiniNaveEnemigaNodriza01 = FVector(100, -1300, 215);
		FVector UbicacionMiniNaveEnemigaNodriza02 = FVector(100, -1500, 215);


		//Spawn NaveEnemiga
		NaveEnemiga01 = GetWorld()->SpawnActor<ANaveEnemiga>(UbicacionNaveEnemiga01, FRotator::ZeroRotator);
		MiniNaveEnemigaCaza01 = GetWorld()->SpawnActor<AMiniNaveEnemigaCaza01>(UbicacionMiniNaveEnemigaCaza01, FRotator::ZeroRotator);
		MiniNaveEnemigaCaza02 = GetWorld()->SpawnActor<AMiniNaveEnemigaCaza02>(UbicacionMiniNaveEnemigaCaza02, FRotator::ZeroRotator);
		MiniNaveEnemigaEspia01 = GetWorld()->SpawnActor<AMiniNaveEnemigaEspia01>(UbicacionMiniNaveEnemigaEspia01, FRotator::ZeroRotator);
		MiniNaveEnemigaEspia02 = GetWorld()->SpawnActor<AMiniNaveEnemigaEspia02>(UbicacionMiniNaveEnemigaEspia02, FRotator::ZeroRotator);
		MiniNaveEnemigaNodriza01 = GetWorld()->SpawnActor<AMiniNaveEnemigaNodriza01>(UbicacionMiniNaveEnemigaNodriza01, FRotator::ZeroRotator);
		MiniNaveEnemigaNodriza02 = GetWorld()->SpawnActor<AMiniNaveEnemigaNodriza02>(UbicacionMiniNaveEnemigaNodriza02, FRotator::ZeroRotator);


		//Spawn InventoryActor
		//InventoryActor=GetWorld()->SpawnActor<AInventoryActor>(FVector(0,0, 214), FRotator::ZeroRotator);
		//Spawn CapsulaVelocidad
		CapsulaVelocidad = GetWorld()->SpawnActor<ACapsulaVelocidad>(FVector(0, 100, 214), FRotator::ZeroRotator);
		//Spawn CapsulaDisparo
		CapsulaDisparo = GetWorld()->SpawnActor<ACapsulaDisparo>(FVector(0, 200, 214), FRotator::ZeroRotator);

		//Spawn MiniNaveEnemigaLoca01
		FVector UbicacionMiniNaveEnemigaLoca01 = FVector(700, -400, 215);
		MiniNaveEnemigaLoca01 = GetWorld()->SpawnActor<AMiniNaveEnemigaLoca01>(UbicacionMiniNaveEnemigaLoca01, FRotator::ZeroRotator);

		//Spawn MiniNaveEnemigaLoca02
		FVector UbicacionMiniNaveEnemigaLoca02 = FVector(800, -400, 215);
		MiniNaveEnemigaLoca02 = GetWorld()->SpawnActor<AMiniNaveEnemigaLoca02>(UbicacionMiniNaveEnemigaLoca02, FRotator::ZeroRotator);

		FVector UbicacionMiniNaveEnemigaLoca03 = FVector(900, -400, 215);
		MiniNaveEnemigaLoca03 = GetWorld()->SpawnActor<AMiniNaveEnemigaLoca03>(UbicacionMiniNaveEnemigaLoca03, FRotator::ZeroRotator);

		FVector UbicacionHierarchyActor = FVector(1000, -400, 215);
		HierarchyActor = GetWorld()->SpawnActor<AHierarchyActor>(UbicacionHierarchyActor, FRotator::ZeroRotator);


	}

	AMapSceneCapture2D* MapSceneCapture2D = GetWorld()->SpawnActor<AMapSceneCapture2D>(AMapSceneCapture2D::StaticClass());

	//Spawn FactoryMethod_Main
	//AFactoryMethod_Main* FactoryMethod_Main = GetWorld()->SpawnActor<AFactoryMethod_Main>(AFactoryMethod_Main::StaticClass());

	//Spawn Builder_Main
	//ABuilder_Main* Builder_Main = GetWorld()->SpawnActor<ABuilder_Main>(ABuilder_Main::StaticClass());

	//Spawn Decorator_Main
	//ADecorator_Main* Decorator_Main = GetWorld()->SpawnActor<ADecorator_Main>(ADecorator_Main::StaticClass());


	//Timer
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &AGalagaGameMode::Reinicio, 10.0f, true, 10.0f);

	//ANaveCommand* NaveCommand = GetWorld()->SpawnActor<ANaveCommand>(ANaveCommand::StaticClass(), FVector(-1030, 980, 215),FRotator::ZeroRotator);

	//AControlCommand* ControlCommand = GetWorld()->SpawnActor<AControlCommand>(AControlCommand::StaticClass());
	//


	//AComenzarAtaqueCommand* ComenzarAtaqueCommand = GetWorld()->SpawnActor<AComenzarAtaqueCommand>(AComenzarAtaqueCommand::StaticClass());
	//
	//ComenzarAtaqueCommand->ComenzarAtaqueCommand(NaveCommand);

	//ControlCommand->DefinirCommand(ComenzarAtaqueCommand);

	//ControlCommand->EjecutarCommand();



}

void AGalagaGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}


void AGalagaGameMode::Reinicio()
{
	//Obtiene el pawn actual



	AGalagaPawn* JugadorEnMundoP = Cast<AGalagaPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (JugadorEnMundoP) {
		JugadorEnMundoP->Destroy();

	}

	AGalagaPawn* JugadorEnMundo = GetWorld()->SpawnActor<AGalagaPawn>(AGalagaPawn::StaticClass(), FVector(-1050,10,215), FRotator::ZeroRotator);
	
	AMyPlayerController* JugadorController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	JugadorController->Possess(JugadorEnMundo);

	JugadorEnMundo->AutoPossessPlayer = EAutoReceiveInput::Player0;


}



