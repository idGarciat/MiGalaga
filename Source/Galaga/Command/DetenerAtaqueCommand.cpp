// Fill out your copyright notice in the Description page of Project Settings.


#include "DetenerAtaqueCommand.h"
#include "NaveCommand.h"

// Sets default values
ADetenerAtaqueCommand::ADetenerAtaqueCommand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADetenerAtaqueCommand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADetenerAtaqueCommand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADetenerAtaqueCommand::DetenerAtaqueCommand(ANaveCommand* NaveCommand_)
{
	this->NaveCommand = NaveCommand_;
}

void ADetenerAtaqueCommand::Execute()
{
	NaveCommand->DetenerAtaque();
}

