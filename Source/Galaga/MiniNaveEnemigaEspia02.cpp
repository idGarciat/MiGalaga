// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaEspia02.h"

AMiniNaveEnemigaEspia02::AMiniNaveEnemigaEspia02()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));
	
	MeshNave->SetMaterial(0, Material.Object);
}
