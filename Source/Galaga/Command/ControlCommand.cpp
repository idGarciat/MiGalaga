// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlCommand.h"

// Sets default values
AControlCommand::AControlCommand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlCommand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlCommand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AControlCommand::DefinirCommand(IGameCommand* Command_)
{
	this->Command = Command_;
}

void AControlCommand::EjecutarCommand()
{
	Command->Execute();
}


