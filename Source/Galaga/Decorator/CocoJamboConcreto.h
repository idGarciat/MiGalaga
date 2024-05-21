// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Musicos.h"
#include "CocoJamboConcreto.generated.h"

UCLASS()
class GALAGA_API ACocoJamboConcreto : public AActor, public IMusicos
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACocoJamboConcreto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float Recibirdano() override { return 5; };
	virtual void Tanier() override {};
	virtual void Pelear() override {};
	virtual void Afinar() override {};
	virtual void SetMesh() override {};

};
