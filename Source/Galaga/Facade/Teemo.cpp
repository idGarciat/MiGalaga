// Fill out your copyright notice in the Description page of Project Settings.


#include "Teemo.h"
#include "DesviarProyectiles.h"

ATeemo::ATeemo()
{
	PrimaryActorTick.bCanEverTick = true;

	LifePoints = 500;
	Armor = 20;
	Velocity = 150;
	Damage = 20;
	AttackSpeed = 1;
	ProyectileType = "Bala";
	bPuedeDesviar = true;
	
}

void ATeemo::BeginPlay()
{
	Super::BeginPlay();
	DesviarProyectiles = GetWorld()->SpawnActor<ADesviarProyectiles>(ADesviarProyectiles::StaticClass());
	DesviarProyectiles->SetOwner(this);

	//FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Adjuntando objeto a otro"));
	// Llama a AttachToComponent para adjuntar el objeto al componente padre.
	//DesviarProyectiles->AttachToComponent(MeshChamps, AttachmentRules);

	DesviarProyectiles->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

}

void ATeemo::Passive()
{
	SetActorHiddenInGame(true);
}

void ATeemo::Ability1()
{
	ProyectileType = "Veneno";
}

void ATeemo::Ability2()
{
	Velocity = 200;
}

void ATeemo::Ability3()
{
	bPuedeDesviar = true;
}

void ATeemo::Ability4()
{

}

void ATeemo::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	DesviarProyectiles->DesviacionProyectiles(Cast<AGalagaProjectile>(Other));

	if (bPuedeDesviar == true) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Desviando Proyectil"));

	}

}


