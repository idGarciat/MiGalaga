// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroeBasico.h"
#include "Heroe.h"

// Sets default values
AHeroeBasico::AHeroeBasico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));

	MeshBasico= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBasico"));
	MeshBasico->SetStaticMesh(ShipMesh.Object);


}

// Called when the game starts or when spawned
void AHeroeBasico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroeBasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (Hero) {

	//	if (Hero->GetOwner() == this) {

	//		UE_LOG(LogTemp, Warning, TEXT("El owner del Heroe es igual al del HeroeBasico"));
	//	}
	//	else {

	//		UE_LOG(LogTemp, Warning, TEXT("El owner del Heroe NO es igual al del HeroeBasico"));

	//	}

	//}else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Heroe no creado"));




}

void AHeroeBasico::BuildHero(FVector StartLocation, FRotator StartRotation)
{

	Hero = GetWorld()->SpawnActor<AHeroe>(StartLocation, StartRotation);

	Hero->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	//Attaching the hero actor to this using bWeldSimulatedBodies

	//FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, true);
	
	//Hero->SetOwner(this);

	//Hero->AttachToActor(Hero->GetOwner(), AttachmentRules);


}

void AHeroeBasico::BuildMesh()
{
	Hero->SetMesh(Mesh1);
}

void AHeroeBasico::BuildMaterial()
{
	Hero->SetMaterial(Material1);
}

void AHeroeBasico::BuildLife()
{
	Hero->SetLife(2000);
}

void AHeroeBasico::BuildSpeed()
{
	Hero->SetSpeed(100);
}

void AHeroeBasico::BuildDamage()
{
	Hero->SetDamage(15);
}

AHeroe* AHeroeBasico::GetHero()
{
	return Hero;
}
