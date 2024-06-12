// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackCommand.h"
#include "MoveCommand.h"
#include "NaveCommand.generated.h"

UCLASS()
class GALAGA_API ANaveCommand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveCommand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* Mesh;

	void ComenzarAtaque();
	void DetenerAtaque();

	void Move();
	void Attack();

private:
	UAttackCommand* AttackCommand;
	UMoveCommand* MoveCommand;

public:

	UAttackCommand* GetAttackCommand() const { return AttackCommand; }
	UMoveCommand* GetMoveCommand() const { return MoveCommand; }

	int i;

	FVector FireDirection;


};
