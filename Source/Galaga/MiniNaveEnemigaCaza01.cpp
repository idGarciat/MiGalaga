// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaCaza01.h"

AMiniNaveEnemigaCaza01::AMiniNaveEnemigaCaza01()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));
	
	MeshNave->SetMaterial(0, Material.Object);

}
