// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameCommand.h"

#include "ControlCommand.generated.h"

UCLASS()
class GALAGA_API AControlCommand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlCommand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	IGameCommand* Command;

public:
	void DefinirCommand(IGameCommand* Command_);
	void EjecutarCommand();

};
