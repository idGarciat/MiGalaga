// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameCommand.h"
#include "DetenerAtaqueCommand.generated.h"

UCLASS()
class GALAGA_API ADetenerAtaqueCommand : public AActor, public IGameCommand
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADetenerAtaqueCommand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ANaveCommand* NaveCommand;

	void DetenerAtaqueCommand(ANaveCommand* NaveCommand_);

	virtual void Execute() override;


};
