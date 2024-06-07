// Fill out your copyright notice in the Description page of Project Settings.


#include "DesviarProyectiles.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../GalagaProjectile.h"

// Sets default values
ADesviarProyectiles::ADesviarProyectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADesviarProyectiles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADesviarProyectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (GetOwner() == nullptr)
	//{
	//	//Destroy();
	//}

}

void ADesviarProyectiles::DesviacionProyectiles(AGalagaProjectile* MyProyectile)
{
	AGalagaProjectile* Proyectile = Cast<AGalagaProjectile>(MyProyectile);
	if (Proyectile != nullptr)
	{
		MyPawn = Cast<AGalagaPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Desviando Proyectil"));

		MyPawn->SetRebote(true);




	}

}


