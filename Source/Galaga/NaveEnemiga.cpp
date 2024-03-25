// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"

ANaveEnemiga::ANaveEnemiga()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");

	MeshNave = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));

	Root->AttachTo(MeshNave);

	MeshNave->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	MeshNave->SetStaticMesh(ShipMesh.Object);

	RootComponent = MeshNave;




	Velocidad = 15;
}

void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mover(DeltaTime);


}

void ANaveEnemiga::Mover(float DeltaTime)
{

	FVector NewLocation = GetActorLocation();

	float DeltaTiempoScaled = DeltaTime * Velocidad;
	float DeltaHeight = FMath::Sin(TiempoTranscurrido + DeltaTiempoScaled) - FMath::Sin(TiempoTranscurrido);
	float DeltaForward = FMath::Cos(TiempoTranscurrido + DeltaTiempoScaled) - FMath::Cos(TiempoTranscurrido);

	NewLocation.Y += DeltaHeight * Velocidad;
	NewLocation.X += DeltaForward * Velocidad;

	TiempoTranscurrido += DeltaTime;

	SetActorLocation(NewLocation);

	const FVector MoveDirection = FVector(DeltaForward, DeltaHeight, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector MoveMent = MoveDirection * Velocidad * DeltaTime;

	if (MoveMent.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = MoveMent.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(MoveMent, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(MoveMent, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}



	//Codigo de movimiento en circulo original
	// 
	// 
	//FVector NewLocation = GetActorLocation();
	//float DeltaHeight = (FMath::Sin(TiempoTranscurrido + DeltaTime) - FMath::Sin(TiempoTranscurrido));
	//NewLocation.Y += DeltaHeight * Velocidad;
	//TiempoTranscurrido += DeltaTime;
	//SetActorLocation(NewLocation);

	//FVector NewLocation2 = GetActorLocation();
	//float DeltaForward = (FMath::Cos(TiempoTranscurrido + DeltaTime) - FMath::Cos(TiempoTranscurrido));
	//NewLocation2.X += DeltaForward * Velocidad;
	//TiempoTranscurrido += DeltaTime;
	//SetActorLocation(NewLocation2);

	//const FVector MoveDirection = FVector(DeltaForward, DeltaHeight, 0.0f).GetClampedToMaxSize(1.0f);
	//const FVector MoveMent = MoveDirection * Velocidad * DeltaTime;

	//if (MoveMent.SizeSquared() > 0.0f)
	//{
	//	const FRotator NewRotation = MoveMent.Rotation();
	//	FHitResult Hit(1.f);
	//	RootComponent->MoveComponent(MoveMent, NewRotation, true, &Hit);

	//	if (Hit.IsValidBlockingHit())
	//	{
	//		const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
	//		const FVector Deflection = FVector::VectorPlaneProject(MoveMent, Normal2D) * (1.f - Hit.Time);
	//		RootComponent->MoveComponent(Deflection, NewRotation, true);
	//	}
	//}
}

void ANaveEnemiga::Disparar()
{
	//Codigo para disparar
}

void ANaveEnemiga::Morir()
{
	//Codigo para morir
}

void ANaveEnemiga::Colisionar()
{
	//Codigo para colisionar
}
