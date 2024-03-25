// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaLoca01.h"

AMiniNaveEnemigaLoca01::AMiniNaveEnemigaLoca01()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/M_Backdrop.M_Backdrop'"));

	MeshNave->SetMaterial(0, Material.Object);

	MovimientoAleatorio = CreateDefaultSubobject<URandomMovementComponent>(TEXT("MovimientoAleatorio"));

}

