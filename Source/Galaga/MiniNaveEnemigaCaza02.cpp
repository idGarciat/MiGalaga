// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaCaza02.h"

AMiniNaveEnemigaCaza02::AMiniNaveEnemigaCaza02()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_AssetPlatform.M_AssetPlatform'"));
	
	MeshNave->SetMaterial(0, Material.Object);
}
