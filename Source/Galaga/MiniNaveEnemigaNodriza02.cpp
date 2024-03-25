// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaNodriza02.h"

AMiniNaveEnemigaNodriza02::AMiniNaveEnemigaNodriza02()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));

	MeshNave->SetMaterial(0, Material.Object);

}
