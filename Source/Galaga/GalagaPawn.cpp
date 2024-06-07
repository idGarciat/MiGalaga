// Copyright Epic Games, Inc. All Rights Reserved.

#include "GalagaPawn.h"
#include "GalagaProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

#include "InventoryComponent.h"
#include "InventoryActor.h"
#include "CapsulaVelocidad.h"
#include "CapsulaDisparo.h"

#include "RotatingActor.h"
#include "Components/SphereComponent.h"

#include "GameFramework/FloatingPawnMovement.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"




const FName AGalagaPawn::MoveForwardBinding("MoveForward");
const FName AGalagaPawn::MoveRightBinding("MoveRight");
const FName AGalagaPawn::FireForwardBinding("FireForward");
const FName AGalagaPawn::FireRightBinding("FireRight");


AGalagaPawn::AGalagaPawn()
{	
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	ShipMeshComponent->bOnlyOwnerSee = false;
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1800.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f,0.f, 0.f);
	FireRate = 0.3f;
	bCanFire = true;

	MyInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");

	Multidisparo = false;
	GunOffset2 = FVector(0.f, 100.f, 0.f);


	NumeroBalas = 8;

	//SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	//SphereComp->AttachToComponent(GetShipMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	//SphereComp->SetSphereRadius(200);

	PuedeSaltar = false;
	EstaSaltando = false;
	TiempoTranscurrido = 0;

	PuedeVolver = false;


	PosicionInicial = FVector(-1150.0,-160, 215);

	SpawnerComponent = CreateDefaultSubobject<UActorSpawnerComponent>(TEXT("SpawnerComponent"));

	SpawnerComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Rebote = false;
	

}

void AGalagaPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);

	PlayerInputComponent->BindAction("DropItem", IE_Pressed, this, &AGalagaPawn::DropItem);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGalagaPawn::Salto);

	PlayerInputComponent->BindAction("Comeback", IE_Pressed, this, &AGalagaPawn::PodraVolver);

	PlayerInputComponent->BindAction("Teleportation", IE_Pressed, this, &AGalagaPawn::Teletransporte);



}

void AGalagaPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);



	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);


	FireShot(FireDirection);

	//Salto
	if (PuedeSaltar == true) {

		TiempoTranscurrido += DeltaSeconds;

		SetActorLocation(GetActorLocation() + FVector(0, 0, 100) * DeltaSeconds);

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Primer if")));

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Tiempo Transcurrido %f"), TiempoTranscurrido));


		if (TiempoTranscurrido >= 1.f) {

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Segundo if")));

			TiempoTranscurrido = 0;

			EstaSaltando = true;

			PuedeSaltar = false;


			
		}


	}


	if (EstaSaltando == true) {

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Tercer if")));

		SetActorLocation(GetActorLocation() - FVector(0, 0, 100) * DeltaSeconds);

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Tiempo Transcurrido %f"), TiempoTranscurrido));


		TiempoTranscurrido += DeltaSeconds;


		if (TiempoTranscurrido >= 1.f) {

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Cuarto if")));

			EstaSaltando = false;

			TiempoTranscurrido = 0;

		}

	}


	//Volver
	if (PuedeVolver == true)
	{
		Volver(DeltaSeconds);

		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Puede Volver")));

		if (GetActorLocation().Equals(PosicionInicial, 100.f)) {
			PuedeVolver = false;
			
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Ya volvio")));


		}
	}




}

void AGalagaPawn::BeginPlay()
{

	Super::BeginPlay();

	//mouse = Cast<APlayerController>(GetController());


	MyMouse = Cast<AMyPlayerController>(GetController());


	//if (mouse)
	//{
	//	mouse->bShowMouseCursor = true;
	//	mouse->bEnableClickEvents = true;
	//	mouse->bEnableMouseOverEvents = true;
	//}




}

void AGalagaPawn::FireShot(FVector FireDirection)
{
	//GEngine -> AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("FireDirection: %s"), *FireDirection.ToString()));

	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{

			if (Multidisparo == true) {
				
				//MultiShots(FireDirection, 8, 0);

				for (int i = 0; i < NumeroBalas; i++)
				{

					int grade = 360 / NumeroBalas;

					UWorld* const World = GetWorld();

					FireDirection = FireDirection.RotateAngleAxis(i * grade, FVector(0, 0, 1));
					const FRotator FireRotation = FireDirection.Rotation();
					const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

					if (World != nullptr)
					{
						// spawn the projectile
						//World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);

						AGalagaProjectile* Projectile = World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
						if (Rebote) 
						{

							GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Rebote es true")));
							Projectile->ProjectileMovement->bShouldBounce = true;
							Projectile->ProjectileMovement->Bounciness = 1;
						
						}
						Projectile->SetOwner(this);


					}

					bCanFire = false;
					World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalagaPawn::ShotTimerExpired, FireRate);

				}


			}
			else {
				MultiShots(FireDirection, 1, 0);
			}
		
			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalagaPawn::MultiShots(FVector FireDirection, int numbers, int i)
{
	int grade = 360/ numbers;

	if (i >= numbers) {
		return;
	}

	UWorld* const World = GetWorld();

	FireDirection = FireDirection.RotateAngleAxis(i * grade, FVector(0, 0, 1));
	const FRotator FireRotation = FireDirection.Rotation();
	const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

	if (World != nullptr)
	{
			// spawn the projectile
			//World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
			AGalagaProjectile* Projectile = World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
			if (Rebote == true)
			{

				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Rebote es true")));
				Projectile->ProjectileMovement->bShouldBounce = true;
				Projectile->ProjectileMovement->Bounciness = 1;
				FTimerHandle Restart;
				
				World->GetTimerManager().SetTimer(Restart, this, &AGalagaPawn::ReboteProyectil, 10,false);
		
			}

			Projectile->SetOwner(this);

	}

	bCanFire = false;
	World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalagaPawn::ShotTimerExpired, FireRate);

	i++;
	MultiShots(FireDirection, numbers, i);

}

void AGalagaPawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGalagaPawn::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No hay items en el inventario")));
		return;
	}
	AInventoryActor* Item =
	MyInventory->CurrentInventory.Last();

	if (Item->IsA(ACapsulaDisparo::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es la capsula disparo")));
		//FireRate = 0.1;
		Multidisparo = true;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Multidisparo es : %b"), Multidisparo));
	}


	if (Item->IsA(ACapsulaVelocidad::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es la capsula velocidad")));
		MoveSpeed = MoveSpeed * 2;
	}



	MyInventory->RemoveFromInventory(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);




}

void AGalagaPawn::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);
}

void AGalagaPawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);

	ACapsulaVelocidad* Capsula = Cast<ACapsulaVelocidad>(Other);

	if (InventoryItem != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es el Inventory Item")));

		TakeItem(InventoryItem);
	}

	//if (Capsula == Other)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es la Capsula")));

	//	MoveSpeed = MoveSpeed * 2;
	//}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Recibi un toque, soy el jugador %s"), *GetName()));


}

void AGalagaPawn::NotifyActorBeginOverlap(AActor* OtherActor)
{

	if (ARotatingActor* RotatingActorCheck = Cast<ARotatingActor>(OtherActor))
	{
		RotatingActorCheck->SetbCanRotate(true);
	
	}

}

void AGalagaPawn::NotifyActorEndOverlap(AActor* OtherActor)
{

	if (ARotatingActor* RotatingActorCheck = Cast<ARotatingActor>(OtherActor))
	{
		RotatingActorCheck->SetbCanRotate(false);
	}

}

void AGalagaPawn::Salto()
{

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Salto")));
	
	PuedeSaltar = true;

}

void AGalagaPawn::Volver(float DeltaSeconds)
{

	SetActorLocation(FMath::VInterpTo(GetActorLocation(), PosicionInicial, DeltaSeconds, 5));


}

void AGalagaPawn::PodraVolver()
{

		PuedeVolver = true;

}

void AGalagaPawn::Teletransporte()
{

	//Transporte

	//Get where the cursor is pointing(only on the ground, channel1)
	FHitResult hit(ForceInit);

	//MyMouse->GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel1, false, hit);

	MyMouse->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, hit);		//Hits any object
	
	FVector v = hit.Location;

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Posicion Mouse: %s"), *v.ToString()));

	SetActorLocation(FVector(v.X, v.Y, GetActorLocation().Z));

}

void AGalagaPawn::ReboteProyectil()
{
	Rebote = false;
}

