// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchyActor.h"
#include "MiniNaveEnemigaEspia02.h"

// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildSceneComponent = CreateDefaultSubobject<USceneComponent> ("ChildSceneComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");
	BoxThree = CreateDefaultSubobject<UStaticMeshComponent>("BoxThree");

	InventoryActor = CreateDefaultSubobject<AInventoryActor>("InventoryActor");
	MiniNaveEnemigaEspia02 = CreateDefaultSubobject<AMiniNaveEnemigaEspia02>("MiniNaveEnemigaEspia02");

	// Get a reference to the cube mesh
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh> (TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	auto MeshAssetHierarchy2 = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));


	// Give both boxes a mesh
	if (MeshAsset.Object != nullptr)
	{
		BoxOne->SetStaticMesh(MeshAssetHierarchy2.Object);
		BoxTwo->SetStaticMesh(MeshAsset.Object);
		BoxThree->SetStaticMesh(MeshAsset.Object);

		//InventoryActor->GetStaticMeshComponent()->SetStaticMesh(ShipMesh.Object);
		MiniNaveEnemigaEspia02->MeshNave->SetStaticMesh(ShipMesh.Object);

	}
	RootComponent = Root;
	// Set up the object's hierarchy
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildSceneComponent);
	BoxThree->AttachTo(ChildSceneComponent);


	//InventoryActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	//MiniNaveEnemigaEspia02->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	ChildSceneComponent->AttachTo(Root);
	// Offset and scale the child from the root
	ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(0.5f)));
	// Offset and scale the boxes from the child
	BoxTwo->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(-100, 0, 0), FVector(1.5f)));
	BoxThree->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(200, 0, 0), FVector(1.5f)));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	//MeshAssetHierarchy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ASSet"));
	//MeshAssetHierarchy->SetStaticMesh(CubeAsset.Object);


	

}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld * const World = GetWorld();

	//Spawn de la nave

	MiniNaveEnemigaEspia02 = GetWorld()->SpawnActor<AMiniNaveEnemigaEspia02>(GetActorLocation() + FVector(50, 50, 0), FRotator::ZeroRotator);

	AdjuntarObjetoAOtro(MiniNaveEnemigaEspia02, Root);

}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// En el método donde deseas realizar la conexión
void AHierarchyActor::AdjuntarObjetoAOtro(AActor* ObjetoAAdjuntar, USceneComponent* ComponentePadre)
{
	if (ObjetoAAdjuntar && ComponentePadre)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Adjuntando objeto a otro"));
		// Llama a AttachToComponent para adjuntar el objeto al componente padre.
		ObjetoAAdjuntar->AttachToComponent(ComponentePadre, FAttachmentTransformRules::KeepWorldTransform);
	}
}

