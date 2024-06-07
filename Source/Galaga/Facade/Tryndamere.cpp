// Fill out your copyright notice in the Description page of Project Settings.


#include "Tryndamere.h"

ATryndamere::ATryndamere()
{

	PrimaryActorTick.bCanEverTick = true;
	LifePoints = 500;
	Armor = 20;
	Velocity = 150;
	Damage = 20;
	AttackSpeed = 1;
	ProyectileType = "Misiles";


}

void ATryndamere::BeginPlay()
{
	Super::BeginPlay();
}


void ATryndamere::Passive()
{

}

void ATryndamere::Ability1()
{

}

void ATryndamere::Ability2()
{

}

void ATryndamere::Ability3()
{

}

void ATryndamere::Ability4()
{

}
