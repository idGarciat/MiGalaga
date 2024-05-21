// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawnerComponent.h"
#include "CapsulaDisparo.h"

// Sets default values for this component's properties
UActorSpawnerComponent::UActorSpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorSpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	SpawnDelay += DeltaTime;

	if (SpawnDelay >= 5.0f)
	{
		Spawn();
		SpawnDelay = 0.0f;
	}

}

void UActorSpawnerComponent::Spawn()
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		//Localizacion en base al actor que tiene el componente

		//FVector Location  = GetComponentLocation();
		//FRotator Rotation = GetComponentRotation();




		//FActorSpawnParameters SpawnInfo;
		ActorToSpawn = ACapsulaDisparo::StaticClass();
		//AActor* NewActor = TheWorld->SpawnActor<AActor>(ActorToSpawn, Location, Rotation, SpawnInfo);
		//
		//if (NewActor != nullptr)
		//{
		//	ACapsulaDisparo* Capsula = Cast<ACapsulaDisparo>(NewActor);
		//	Mensaje de la localización de la capsula,etc.
		//	if (Capsula != nullptr)
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("Capsula Disparo Spawned at %s"), *Location.ToString());
		//	}
		//}

		//Spawn basado en la ubicacion del actor donde esta 
	}
}

