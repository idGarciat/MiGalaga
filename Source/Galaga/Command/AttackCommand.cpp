// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackCommand.h"
#include "NaveCommand.h"

// Sets default values for this component's properties
UAttackCommand::UAttackCommand()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttackCommand::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttackCommand::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAttackCommand::AttackCommand(ANaveCommand* NaveCommand_)
{
	this->NaveCommand = NaveCommand_;
}

void UAttackCommand::Execute()
{
	NaveCommand->Attack();
}

