// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nave.generated.h"

UCLASS(Abstract)
class GALAGA_API ANave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshNave;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;



protected:
	int vida;
	int Velocidad;
	int danio;
	int puntaje;
	int tiempoDisparo;
	float TiempoTranscurrido;

	//Disparo

	bool PuedeDisparar;
	FVector GunOffset;
	float CadenciaDisparo;
	FTimerHandle TimerHandle_ShotTimerExpired;
	FTimerHandle MemberTimerHandle;

public:
	FORCEINLINE int GetVida() const { return vida; }
	FORCEINLINE float GetVelocidad() const { return Velocidad; }
	FORCEINLINE int GetDanio() const { return danio; }
	FORCEINLINE int GetPuntaje() const { return puntaje; }
	FORCEINLINE int GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE float GetTiempoTranscurrido() const { return TiempoTranscurrido; }

	FORCEINLINE void SetVida(int _vida) { vida = _vida; }
	FORCEINLINE void SetVelocidad(int _Velocidad) { Velocidad = _Velocidad; }
	FORCEINLINE void SetDanio(int _danio) { danio = _danio; }
	FORCEINLINE void SetPuntaje(int _puntaje) { puntaje = _puntaje; }
	FORCEINLINE void SetTiempoDisparo(int _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetTiempoTranscurrido(float _tiempoTranscurrido) { TiempoTranscurrido = _tiempoTranscurrido; }



public:
	virtual void Mover() PURE_VIRTUAL(ANaveEnemiga::Mover);
	virtual void Disparar(FVector DireccionDisparo) PURE_VIRTUAL(ANaveEnemiga::Disparar);
	virtual void TiempoDisparoExpirado() PURE_VIRTUAL(ANaveEnemiga::TiempoDisparoExpirado);
	virtual void Disparo() PURE_VIRTUAL(ANaveEnemiga::Disparo);

	virtual void Morir() PURE_VIRTUAL(ANaveEnemiga::Morir);

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) PURE_VIRTUAL(ANaveEnemiga::NotifyHit);


};
