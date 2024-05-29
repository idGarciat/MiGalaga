// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrera.h"

// Sets default values
ABarrera::ABarrera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));

	MeshBarrera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBarrera"));
	RootComponent = MeshBarrera;
	MeshBarrera->SetStaticMesh(MeshAsset.Object);
	MeshBarrera->SetMaterial(0, MaterialAsset.Object);


}

// Called when the game starts or when spawned
void ABarrera::BeginPlay()
{
	Super::BeginPlay();
	
	UMaterialInterface* Material = MeshBarrera->GetMaterial(0);

	UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(Material, this);

	MeshBarrera->SetMaterial(0, DynamicMaterialInstance);


	//DynamicMaterialInstance->SetScalarParameterValue(FName("Opacity"), 1.0f);
}

// Called every frame
void ABarrera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//MeshBarrera->SetRelativeScale3D(MeshBarrera->GetRelativeScale3D() + DeltaTime);

}




