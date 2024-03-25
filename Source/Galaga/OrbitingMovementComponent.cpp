// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbitingMovementComponent.h"
#include "TimerManager.h"



// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	RotationSpeed = 100;
	OrbitDistance = 1;
	CurrentValue = 0;
	RotateToFaceOutwards = true;
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	UWorld* const World = GetWorld();


}


// Called every frame
void UOrbitingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	float CurrentValueInRadians = FMath::DegreesToRadians<float>(CurrentValue);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Current Value: %f"), CurrentValue));

	SetRelativeLocation( FVector(
		OrbitDistance * FMath::Cos(CurrentValueInRadians), 
		OrbitDistance * FMath::Sin(CurrentValueInRadians),
		GetRelativeLocation().Z)
	);
	if (RotateToFaceOutwards)
	{
		FVector LookDir = (GetRelativeLocation()).GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot);
	}
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed *DeltaTime), 360);

}

