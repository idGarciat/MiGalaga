// Fill out your copyright notice in the Description page of Project Settings.


#include "FachadaCampeones.h"
#include "Teemo.h"
#include "Trunde.h"
#include "Tryndamere.h"

// Sets default values
AFachadaCampeones::AFachadaCampeones()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFachadaCampeones::BeginPlay()
{
	Super::BeginPlay();
	
	//Initialize the lists
	Champions = TArray<ACampeones*>();

	Tasks = TArray<FString>();

	//Spawn the members
	ATeemo* Teemo = GetWorld()->SpawnActor<ATeemo>(ATeemo::StaticClass());
	ATrunde* Trunde = GetWorld()->SpawnActor<ATrunde>(ATrunde::StaticClass());
	ATryndamere* Tryndamere = GetWorld()->SpawnActor<ATryndamere>(ATryndamere::StaticClass());
	//Add the member to the crew
	Champions.Add(Teemo);
	Champions.Add(Trunde);
	Champions.Add(Tryndamere);

}

// Called every frame
void AFachadaCampeones::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFachadaCampeones::Push()
{
	//Empty the task list
	Tasks.Empty();
	//Add the tasks to execute
	Tasks.Add("Attack");
	Tasks.Add("Ability1");
	Tasks.Add("Ability2");
	//Execute the tasks
	PerformTasks(Champions, Tasks);
}

void AFachadaCampeones::Defend()
{
	//Empty the task list
	Tasks.Empty();
	//Add the tasks to execute
	Tasks.Add("Attack");
	Tasks.Add("Ability2");
	Tasks.Add("Ability3");
	//Execute the tasks
	PerformTasks(Champions, Tasks);
}

void AFachadaCampeones::Scape()
{
	//Empty the task list
	Tasks.Empty();
	//Add the tasks to execute
	Tasks.Add("Passive");
	Tasks.Add("Ability4");
	//Execute the tasks
	PerformTasks(Champions, Tasks);
}

void AFachadaCampeones::PerformTasks(TArray<ACampeones*> myChampions, TArray<FString> myTasks)
{
	//Execute the passed tasks for each crew member
	for (ACampeones* Champion : myChampions)
	{
		//Execute the task
		Champion->ExecuteTask(myTasks);
	}
}
