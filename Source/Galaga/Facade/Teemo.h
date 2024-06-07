// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Campeones.h"
#include "Teemo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ATeemo : public ACampeones
{
	GENERATED_BODY()

public:
	ATeemo();
	virtual void BeginPlay() override;

	virtual void Passive() override;
	virtual void Ability1() override;
	virtual void Ability2() override;
	virtual void Ability3() override;
	virtual void Ability4() override;


	ADesviarProyectiles* DesviarProyectiles;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	bool bPuedeDesviar;
};
