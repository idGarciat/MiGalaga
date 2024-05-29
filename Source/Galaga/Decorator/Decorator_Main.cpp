// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorator_Main.h"
#include "CocoBaterista.h"
#include "CocoCantante.h"
#include "CocoJamboConcreto.h"
#include "CocoJambo.h"

// Sets default values
ADecorator_Main::ADecorator_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecorator_Main::BeginPlay()
{
	Super::BeginPlay();

	//ACocoJambo* CocoJambo = GetWorld()->SpawnActor<ACocoJambo>(ACocoJambo::StaticClass());

	ACocoJamboConcreto* CocoConcreto = GetWorld()->SpawnActor<ACocoJamboConcreto>(ACocoJamboConcreto::StaticClass(), FVector(0,1000,0),FRotator::ZeroRotator);

	ACocoCantante* CocoCantante = GetWorld()->SpawnActor<ACocoCantante>(ACocoCantante::StaticClass(), FVector(1000,0,0), FRotator::ZeroRotator);
	CocoCantante->SetMusicos(CocoConcreto);


	ACocoBaterista* CocoBaterista = GetWorld()->SpawnActor<ACocoBaterista>(ACocoBaterista::StaticClass());
	CocoBaterista->SetMusicos(CocoCantante);

	ACocoJambo* CocoJambo = GetWorld()->SpawnActor<ACocoJambo>(ACocoJambo::StaticClass());




	Musico = CocoCantante;
	Musico->GetActorsInSphere();
	Musico->Recibirdano();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Melee Enemies cause %f damage."), Musico->Recibirdano()));


	Musico = CocoBaterista;
	Musico->GetActorsInSphere();
	Musico->Recibirdano();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Melee Enemies cause %f damage."), Musico->Recibirdano()));



	Musico = CocoBaterista;



}

// Called every frame
void ADecorator_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Tiempo += DeltaTime;
	if (Tiempo >= 5.0f)
	{
		if (Musico != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("5 segundos han pasado"));
			//UE_LOG(LogTemp, Warning, TEXT("5 segundos han pasado"));

			Musico->GetActorsInSphere();
			Musico->Recibirdano();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Melee Enemies cause %f damage."), Musico->Recibirdano()));

			Tiempo = 0.0f;
		}

	}

}

