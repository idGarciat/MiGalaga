// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCommand.h"
#include "NaveCommand.h"

// Sets default values for this component's properties
UMoveCommand::UMoveCommand()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveCommand::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMoveCommand::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMoveCommand::MoveCommand(ANaveCommand* NaveCommand_)
{
	this->NaveCommand = NaveCommand_;
}

void UMoveCommand::Execute()
{
	NaveCommand->Move();
}

