// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CocoJambo.h"
#include "CocoBaterista.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_API ACocoBaterista : public ACocoJambo
{
	GENERATED_BODY()
	
public:
	virtual float Recibirdano() override;
	virtual void Tanier() override;
	virtual void Pelear() override;
	virtual void Afinar() override;
	virtual void SetMesh() override;

};
