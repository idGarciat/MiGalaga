// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Heroe.generated.h"

UCLASS()
class GALAGA_API AHeroe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshHero;

	UPROPERTY(VisibleAnywhere)
	int LifeHero;

	UPROPERTY(VisibleAnywhere)
	float SpeedHero;

	UPROPERTY(VisibleAnywhere)
	int DamageHero;

public:
	void SetMesh(class UStaticMesh* Mesh);
	void SetMaterial(class UMaterial* Material);
	void SetLife(int Life);
	void SetSpeed(float Speed);
	void SetDamage(int Damage);

	void HeroCharacteristics();



};
