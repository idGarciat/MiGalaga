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



const FName AGalagaPawn::MoveForwardBinding("MoveForward");
const FName AGalagaPawn::MoveRightBinding("MoveRight");
const FName AGalagaPawn::FireForwardBinding("FireForward");
const FName AGalagaPawn::FireRightBinding("FireRight");

const FName AGalagaPawn::DisparoVertical("DisparoVertical");
const FName AGalagaPawn::DisparoHorizontal("DisparoHorizontal");

AGalagaPawn::AGalagaPawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
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

	a = false;
	GunOffset2 = FVector(0.f, 100.f, 0.f);


	NumeroBalas = 8;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->AttachToComponent(GetShipMeshComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	SphereComp->SetSphereRadius(200);

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
	PlayerInputComponent->BindAction("DisparoDireccion", IE_Pressed, this, &AGalagaPawn::DisparoDireccion);

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

			if (a == true) {
				
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
						World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
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
			World->SpawnActor<AGalagaProjectile>(SpawnLocation, FireRotation);
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
		return;
	}
	AInventoryActor* Item =
	MyInventory->CurrentInventory.Last();

	if (Item->IsA(ACapsulaDisparo::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es la capsula disparo")));
		//FireRate = 0.1;
		a = true;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("a es : %b"), a));
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
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es el Inventory Item")));

		TakeItem(InventoryItem);
	}

	//if (Capsula == Other)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es la Capsula")));

	//	MoveSpeed = MoveSpeed * 2;
	//}


}

void AGalagaPawn::Disparo()
{
	// Create fire direction vector
	const float ValorDisparoVertical = GetInputAxisValue(DisparoVertical);
	const float ValorDisparoHorizontal = GetInputAxisValue(DisparoVertical);
	const FVector DireccionDisparo = FVector(ValorDisparoVertical, ValorDisparoHorizontal, 0.f);
}

void AGalagaPawn::DisparoDireccion()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("DisparoDireccion")));

	FireShot(FVector(1,0,0));
	//FireShot(FVector(0, 1, 0));


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

