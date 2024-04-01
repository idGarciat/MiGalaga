// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaLoca02.h"

AMiniNaveEnemigaLoca02::AMiniNaveEnemigaLoca02()
{
	
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_ColorGrid_LowSpec.M_ColorGrid_LowSpec'"));

	MeshNave->SetMaterial(0, Material.Object);

	OrbitingMovement = CreateDefaultSubobject<UOrbitingMovementComponent>(TEXT("OrbitingMovement"));

	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");
	BoxThree = CreateDefaultSubobject<UStaticMeshComponent>("BoxThree");

	MiniNaveEnemigaCaza01 = CreateDefaultSubobject<AMiniNaveEnemigaCaza01>("MiniNaveEnemigaCaza01");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	auto MeshAssetHierarchy2 = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));

	// Give both boxes a mesh
	if (MeshAsset.Object != nullptr)
	{
		BoxOne->SetStaticMesh(MeshAssetHierarchy2.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
		BoxThree->SetStaticMesh(MeshAsset.Object);

	}



	OrbitingMovement->AttachTo(Root);

	BoxOne->AttachTo(OrbitingMovement);
	BoxTwo->AttachTo(OrbitingMovement);
	BoxThree->AttachTo(OrbitingMovement);

	//MiniNaveEnemigaCaza01->AttachToComponent(OrbitingMovement, FAttachmentTransformRules::KeepRelativeTransform);


	BoxOne->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(-150, 0, 0), FVector(1.f)));
	BoxTwo->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(150, 0, 0), FVector(1.f)));
	BoxThree->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 150, 0), FVector(1.f)));

	//BoxOne->DestroyComponent();
	//BoxTwo->DestroyComponent();
	//BoxThree->DestroyComponent();

}

void AMiniNaveEnemigaLoca02::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();

	//Spawn de la nave

	MiniNaveEnemigaCaza01 = GetWorld()->SpawnActor<AMiniNaveEnemigaCaza01>(GetActorLocation() + FVector(0, -150, 0), FRotator::ZeroRotator);

	AdjuntarObjetoAOtro(MiniNaveEnemigaCaza01, OrbitingMovement);
}

// En el método donde deseas realizar la conexión
void AMiniNaveEnemigaLoca02::AdjuntarObjetoAOtro(AActor* ObjetoAAdjuntar, USceneComponent* ComponentePadre)
{
	if (ObjetoAAdjuntar && ComponentePadre)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Adjuntando objeto a otro"));
		// Llama a AttachToComponent para adjuntar el objeto al componente padre.
		ObjetoAAdjuntar->AttachToComponent(ComponentePadre, FAttachmentTransformRules::KeepWorldTransform);
	}
}
