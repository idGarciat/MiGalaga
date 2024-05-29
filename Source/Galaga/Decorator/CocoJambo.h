// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Musicos.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#include "CocoJambo.generated.h"

UCLASS()
class GALAGA_API ACocoJambo : public AActor, public IMusicos
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACocoJambo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	IMusicos* Musicos;

public:

	UStaticMeshComponent* MeshCoco;
	USkeletalMeshComponent* SkeletalCoco;

public:
	virtual float Recibirdano() override;
	virtual void Tanier() override;
	virtual void Pelear() override;
	virtual void Afinar() override;
	virtual void SetMesh() override;



	void SetMusicos(IMusicos* NewMusicos) {
		Musicos = NewMusicos;
	}

	IMusicos* GetMusicos() {
		return Musicos;
	}


	virtual TArray<AActor*> GetActorsInSphere() override;
	float Radius;
	FVector Center;
	TArray<AActor*> OverlappingActors;

	float tiempotranscurrido;
};
