// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InventoryActor.h"
#include "MiniNaveEnemigaEspia02.h"

#include "HierarchyActor.generated.h"

UCLASS()
class GALAGA_API AHierarchyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHierarchyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AdjuntarObjetoAOtro(AActor* ObjetoAAdjuntar, USceneComponent* ComponentePadre);


	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ChildSceneComponent;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxOne;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxTwo;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxThree;

	//Mesh del actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshAssetHierarchy;


	UPROPERTY(VisibleAnywhere)
	AInventoryActor* InventoryActor;

	UPROPERTY(VisibleAnywhere)
	AMiniNaveEnemigaEspia02* MiniNaveEnemigaEspia02;

};
