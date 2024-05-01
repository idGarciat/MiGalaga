// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Builder_Main.generated.h"

UCLASS()
class GALAGA_API ABuilder_Main : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder_Main();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(VisibleAnywhere, Category = "Heroe")
	class ABioIngeniero* BioIngeniero;

	UPROPERTY(VisibleAnywhere, Category = "Heroe")
	class AHeroeBasico* HeroeBasico;

	UPROPERTY(VisibleAnywhere, Category = "Heroe")
	class AHeroeInfectado* HeroeInfectado;

	UPROPERTY(VisibleAnywhere, Category = "Heroe")
	class AHeroeFuturista* HeroeFuturista;

};
