// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCommand.h"
#include "../GalagaProjectile.h"
#include "../MiniNaveEnemigaNodriza02.h"
// Sets default values
ANaveCommand::ANaveCommand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));



	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	//Mesh->AttachTo(RootComponent);

	Mesh->SetStaticMesh(MeshAsset.Object);
	

	//AttackCommand = CreateDefaultSubobject<UAttackCommand>(TEXT("AttackCommand"));
	//MoveCommand = CreateDefaultSubobject<UMoveCommand>(TEXT("MoveCommand"));


	i = 1;
	FireDirection = FVector(1, 0, 0);
}

// Called when the game starts or when spawned
void ANaveCommand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveCommand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANaveCommand::ComenzarAtaque()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("ComenzarAtaque"));

	GetWorld()->SpawnActor<AMiniNaveEnemigaNodriza02>(AMiniNaveEnemigaNodriza02::StaticClass(), GetActorLocation() + 200 , FRotator::ZeroRotator);

}

void ANaveCommand::DetenerAtaque()
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("DetenerAtaque"));

}

void ANaveCommand::Move()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("MoveIendose"));

}

void ANaveCommand::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, TEXT("AttackAndo"));

}

