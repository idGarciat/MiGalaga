// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaDisparo.h"

ACapsulaDisparo::ACapsulaDisparo()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/M_Backdrop.M_Backdrop'"));

	GetStaticMeshComponent()->SetMaterial(0, Material.Object);
}
