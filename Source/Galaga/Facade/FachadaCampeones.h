// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Campeones.h"
#include "FachadaCampeones.generated.h"

UCLASS()
class GALAGA_API AFachadaCampeones : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFachadaCampeones();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Crew list
	TArray<ACampeones*> Champions;
	//The Tasks to execute
	UPROPERTY()
	TArray<FString> Tasks;

private:
	//Execute the tasks for a specific Crew
	void PerformTasks(TArray<ACampeones*> myChampions, TArray<FString> myTasks);

public:

	//Execute the Reveille tasks
	void Push();
	//Execute the PlanOfTheDay tasks
	void Defend();
	//Execute the Taps tasks
	void Scape();

};
