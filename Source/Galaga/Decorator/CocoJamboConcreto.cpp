// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoJamboConcreto.h"

// Sets default values
ACocoJamboConcreto::ACocoJamboConcreto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshCoco = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCoco"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MeshCustom/fuwa-fuwa-hololive-suisei-release-10/source/FuwaFuwaHololiveSuisei_Release_V1_FuwaSuisei.FuwaFuwaHololiveSuisei_Release_V1_FuwaSuisei'"));

	//MeshCoco->SetStaticMesh(MeshAsset.Object);

	//SkeletalCoco = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalCoco"));

	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("StaticMesh'/Game/MeshCustom/fuwa-fuwa-hololive-suisei-release-10/source/FuwaFuwaHololiveSuisei_Release_V1_FuwaSuisei.FuwaFuwaHololiveSuisei_Release_V1_FuwaSuisei'"));


	//SkeletalCoco->SetSkeletalMesh(SkeletalMeshAsset.Object);

	MeshCoco->SetStaticMesh(MeshAsset.Object);
	MeshCoco->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	MeshCoco->SetRelativeRotation(FRotator(0.0f, 90.0f, -120.0f));


	//SkeletalCoco->AttachToComponent(MeshCoco, FAttachmentTransformRules::KeepRelativeTransform);
	RootComponent = MeshCoco;

}

// Called when the game starts or when spawned
void ACocoJamboConcreto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACocoJamboConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



