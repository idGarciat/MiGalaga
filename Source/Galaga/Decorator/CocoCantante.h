// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CocoJambo.h"
#include "CocoCantante.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ACocoCantante : public ACocoJambo
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual float Recibirdano() override;
	virtual void Tanier() override;
	virtual void Pelear() override;
	virtual void Afinar() override;
	virtual void SetMesh() override;

	virtual TArray<AActor*> GetActorsInSphere() override;


};
