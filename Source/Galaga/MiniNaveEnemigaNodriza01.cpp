// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaNodriza01.h"

AMiniNaveEnemigaNodriza01::AMiniNaveEnemigaNodriza01()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'"));

	MeshNave->SetMaterial(0, Material.Object);

}
