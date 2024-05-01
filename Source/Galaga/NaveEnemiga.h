// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ANaveEnemiga : public ANave
{
	GENERATED_BODY()


public:
	ANaveEnemiga();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Mover(float DeltaTime);

	virtual void Disparar(FVector DireccionDisparo);
	virtual void TiempoDisparoExpirado();
	virtual void Disparo();


	virtual void Morir();

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	float NewX;
	float NewY;



	
};
