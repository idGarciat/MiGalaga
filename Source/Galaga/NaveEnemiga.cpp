// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "GalagaProjectile.h"
#include "GalagaPawn.h"
#include "Kismet/GameplayStatics.h"


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




	Velocidad = 100;
	CadenciaDisparo = 2.0f;
	PuedeDisparar = false;
}

void ANaveEnemiga::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//Mover(DeltaSeconds);


	srand(time(NULL));//toma el tiempo de la computadora y esto hace que no halla randoms iguales

	


	NewX = rand() % 3 -1;
	NewY = rand() % 3 -1;
	//SetActorLocation(NewLocation);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NewX: %f"), NewX));

	const FVector MoveDirection = FVector(NewX, NewY, 0.0f);
	const FVector MoveMent = MoveDirection * Velocidad * DeltaSeconds;

	if (MoveMent.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = MoveMent.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(MoveMent, NewRotation, true, &Hit);

		//if (Hit.IsValidBlockingHit())
		//{
		//	const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
		//	const FVector Deflection = FVector::VectorPlaneProject(MoveMent, Normal2D) * (1.f - Hit.Time);
		//	RootComponent->MoveComponent(Deflection, NewRotation, true);
		//}
	}
}

void ANaveEnemiga::Mover(float DeltaSeconds)
{

	FVector NewLocation = GetActorLocation();

	float DeltaTiempoScaled = DeltaSeconds * Velocidad;
	float DeltaHeight = FMath::Sin(TiempoTranscurrido + DeltaTiempoScaled) - FMath::Sin(TiempoTranscurrido);
	float DeltaForward = FMath::Cos(TiempoTranscurrido + DeltaTiempoScaled) - FMath::Cos(TiempoTranscurrido);

	NewLocation.Y += DeltaHeight * Velocidad;
	NewLocation.X += DeltaForward * Velocidad;


	

	TiempoTranscurrido += DeltaSeconds;

	NewX = FMath::RandRange(-2, 2);
	NewY = FMath::RandRange(-2, 2);

	//SetActorLocation(NewLocation);

	const FVector MoveDirection = FVector(NewX, NewY, 0.0f);
	const FVector MoveMent = MoveDirection * Velocidad * DeltaSeconds;

	if (MoveMent.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = MoveMent.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(MoveMent, NewRotation, true, &Hit);

		//if (Hit.IsValidBlockingHit())
		//{
		//	const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
		//	const FVector Deflection = FVector::VectorPlaneProject(MoveMent, Normal2D) * (1.f - Hit.Time);
		//	RootComponent->MoveComponent(Deflection, NewRotation, true);
		//}
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

void ANaveEnemiga::Disparar(FVector DireccionDisparo)
{
	//Codigo para disparar
	if (PuedeDisparar == true)
	{
		if (DireccionDisparo.SizeSquared() > 0.0f)
		{
			AGalagaPawn* avatar = Cast<AGalagaPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
			//ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));//obtenemos la ubicacion de la naveJugador
			if (!avatar)
			{
				return;

			}
			FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();

			const FRotator FireRotation = toPlayer.Rotation(); //unimos el vector que apunta al jugador con una rotacion
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();

			if (World != nullptr)
			{

				World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
			}

			PuedeDisparar = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemiga::TiempoDisparoExpirado, CadenciaDisparo);//funcion que hace desaparecer la bala en un tiempo

		}
	}


}

void ANaveEnemiga::TiempoDisparoExpirado()
{
	PuedeDisparar = true;
}

void ANaveEnemiga::Disparo()
{
	PuedeDisparar = true;

	srand(time(NULL));//toma el tiempo de la computadora y esto hace que no halla randoms iguales

	float MovingAX = rand() % 18 - 10; //random eje X 
	float MovingAY = rand() % 18 - 10; //random eje Y 


	const FVector FireDirection = FVector(MovingAX, MovingAY, 0.0f).GetClampedToMaxSize(1.0f);
	Disparar(FireDirection); //llamamos a la funcion FireShot


}

void ANaveEnemiga::Morir()
{
	Destroy();
}



void ANaveEnemiga::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Codigo para notificar que fue golpeado con el proyectil
	AGalagaProjectile* Proyectil = Cast<AGalagaProjectile>(Other);

	if (Proyectil)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hit")));

		Morir();
	}

}
