// Fill out your copyright notice in the Description page of Project Settings.


#include "Heroe.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AHeroe::AHeroe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshHero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	MeshHero->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

}

// Called when the game starts or when spawned
void AHeroe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeroe::SetMesh(UStaticMesh* Mesh)
{
	MeshHero->SetStaticMesh(Mesh);
}

void AHeroe::SetMaterial(UMaterial* Material)
{
	 MeshHero->SetMaterial(0, Material);
}

void AHeroe::SetLife(int Life)
{
	LifeHero = Life;
}

void AHeroe::SetSpeed(float Speed)
{
	SpeedHero = Speed;
}

void AHeroe::SetDamage(int Damage)
{
	DamageHero = Damage;
}

void AHeroe::HeroCharacteristics()
{
	UE_LOG(LogTemp, Warning, TEXT("Heroe: %s"), *GetName());
	UE_LOG(LogTemp, Warning, TEXT("Mesh: %s"), *MeshHero->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Material: %s"), *MeshHero->GetMaterial(0)->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Life: %d"), LifeHero);
	UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), SpeedHero);
	UE_LOG(LogTemp, Warning, TEXT("Damage: %d"), DamageHero);
	//Message that shows InGame
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Heroe: %s"), *GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Mesh: %s"), *MeshHero->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Material: %s"), *MeshHero->GetMaterial(0)->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Life: %d"), LifeHero));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Speed: %f"), SpeedHero));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Damage: %d"), DamageHero));


}

