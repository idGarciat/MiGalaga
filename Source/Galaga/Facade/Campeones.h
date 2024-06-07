// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Campeones.generated.h"

UCLASS()
class GALAGA_API ACampeones : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACampeones();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UStaticMeshComponent* MeshChamps;
	float Velocity;
	float LifePoints;
	float Damage;
	float AttackSpeed;
	float Armor;
	FString ProyectileType;


public:


	virtual void Movement(float DeltaTime);
	virtual void Attack();


	virtual void Passive() PURE_VIRTUAL(ACampeones::Pasiva, ;);
	virtual void Ability1() PURE_VIRTUAL(ACampeones::Ability1, ;);
	virtual void Ability2() PURE_VIRTUAL(ACampeones::Ability2, ;);
	virtual void Ability3() PURE_VIRTUAL(ACampeones::Ability3, ;);
	virtual void Ability4() PURE_VIRTUAL(ACampeones::Ability4, ;);

private:
	//Execute the passed Task
	void RecieveTask(const FString& Task);

public:
	//Execute the passed Tasks
	void ExecuteTask(const TArray<FString>& Tasks);



};
