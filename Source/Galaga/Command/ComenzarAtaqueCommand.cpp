// Fill out your copyright notice in the Description page of Project Settings.


#include "ComenzarAtaqueCommand.h"
#include "NaveCommand.h"

// Sets default values
AComenzarAtaqueCommand::AComenzarAtaqueCommand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AComenzarAtaqueCommand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComenzarAtaqueCommand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AComenzarAtaqueCommand::ComenzarAtaqueCommand(ANaveCommand* NaveCommand_)
{
	this->NaveCommand = NaveCommand_;
}

void AComenzarAtaqueCommand::Execute()
{
	NaveCommand->ComenzarAtaque();
}

