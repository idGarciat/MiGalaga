// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameCommand.h"
#include "MoveCommand.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_API UMoveCommand : public UActorComponent, public IGameCommand
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveCommand();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	class ANaveCommand* NaveCommand;

	void MoveCommand(ANaveCommand* NaveCommand_);

	virtual void Execute() override;
		
};
