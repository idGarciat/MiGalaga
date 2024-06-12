// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameCommand.h"
#include "ComenzarAtaqueCommand.generated.h"

UCLASS()
class GALAGA_API AComenzarAtaqueCommand : public AActor, public IGameCommand
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComenzarAtaqueCommand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ANaveCommand* NaveCommand;

	void ComenzarAtaqueCommand(ANaveCommand* NaveCommand_);

	virtual void Execute() override;

};
