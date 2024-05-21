// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreadorHeroes.h"
#include "HeroeBasico.generated.h"

UCLASS()
class GALAGA_API AHeroeBasico : public AActor, public ICreadorHeroes
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroeBasico();

	UStaticMeshComponent* MeshBasico;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Heroe")
	class AHeroe* Hero;

public:

	void BuildMesh() override;
	void BuildMaterial() override;
	void BuildLife() override;
	void BuildSpeed() override;
	void BuildDamage() override;
	void BuildHero(FVector StartLocation, FRotator StartRotation) override;
	class AHeroe* GetHero() override;

	class UMaterial* Material1 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/MeshCustom/9236af7611d6_Big_Space_Ship_like_texture_kd_Mat.9236af7611d6_Big_Space_Ship_like_texture_kd_Mat'"));

	//definir un mesh globalmente
	class UStaticMesh* Mesh1= LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/MeshCustom/9236af7611d6_Big_Space_Ship_like.9236af7611d6_Big_Space_Ship_like'"));

	


};
