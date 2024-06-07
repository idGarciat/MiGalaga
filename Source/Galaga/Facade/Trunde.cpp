// Fill out your copyright notice in the Description page of Project Settings.


#include "Trunde.h"

ATrunde::ATrunde()
{
	PrimaryActorTick.bCanEverTick = true;

	LifePoints = 500;
	Armor = 20;
	Velocity = 150;
	Damage = 20;
	AttackSpeed = 1;
	ProyectileType = "Bombas";
}

void ATrunde::BeginPlay()
{
	Super::BeginPlay();
}

void ATrunde::Passive()
{

}

void ATrunde::Ability1()
{

}

void ATrunde::Ability2()
{
}

void ATrunde::Ability3()
{
}

void ATrunde::Ability4()
{
}
