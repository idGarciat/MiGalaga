// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaEspia01.h"

AMiniNaveEnemigaEspia01::AMiniNaveEnemigaEspia01()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));
	
	MeshNave->SetMaterial(0, Material.Object);
}

