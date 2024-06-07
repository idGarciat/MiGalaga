// Fill out your copyright notice in the Description page of Project Settings.


#include "Campeones.h"

// Sets default values
ACampeones::ACampeones()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshChampsAsset(TEXT("StaticMesh'/Game/AssetsCustom/wow-sword-test-uv-and-substance-painter/textures/Espadachida.Espadachida'"));
	MeshChamps = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshChamps"));
	MeshChamps->SetStaticMesh(MeshChampsAsset.Object);

}

// Called when the game starts or when spawned
void ACampeones::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACampeones::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	Movement(DeltaTime);
}

void ACampeones::Movement(float DeltaTime)
{

}

void ACampeones::Attack()
{

}

void ACampeones::RecieveTask(const FString& Task)
{
	//Checks which task must be executed
	if (Task.Equals("Attack"))
	{
		Attack();
	}
	else if (Task.Equals("Passive"))
	{
		Passive();
	}
	else if (Task.Equals("Ability1"))
	{
		Ability1();
	}
	else if (Task.Equals("Ability2"))
	{
		Ability2();
	}
	else if (Task.Equals("Ability3"))
	{
		Ability3();
	}
	else if (Task.Equals("Ability4"))
	{
		Ability4();
	}
	else
	{
		//In case the passed Task doesn't exist
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Esa wea no existe wey"));
	}
}

void ACampeones::ExecuteTask(const TArray<FString>& Tasks)
{
	//Loop the Tasks array and call the Task() function for each of them
	for (const FString& myTask : Tasks)
	{
		RecieveTask(myTask);
	}
}