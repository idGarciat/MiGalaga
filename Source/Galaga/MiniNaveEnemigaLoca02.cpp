// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaLoca02.h"

AMiniNaveEnemigaLoca02::AMiniNaveEnemigaLoca02()
{
	
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_ColorGrid_LowSpec.M_ColorGrid_LowSpec'"));

	MeshNave->SetMaterial(0, Material.Object);

	OrbitingMovement = CreateDefaultSubobject<UOrbitingMovementComponent>(TEXT("OrbitingMovement"));

	OrbitingMovement->AttachTo(Root);

}
