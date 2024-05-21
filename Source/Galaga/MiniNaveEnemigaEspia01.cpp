// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniNaveEnemigaEspia01.h"
#include "GalagaProjectile.h"
#include "GalagaPawn.h"
#include "Kismet/GameplayStatics.h"


AMiniNaveEnemigaEspia01::AMiniNaveEnemigaEspia01()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));
	
	MeshNave->SetMaterial(0, Material.Object);

	PuedeDisparar = true;
}

void AMiniNaveEnemigaEspia01::BeginPlay()
{
		Super::BeginPlay();

		GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMiniNaveEnemigaEspia01::Disparo, 01.0f, true, 0.0f);
}

void AMiniNaveEnemigaEspia01::Disparar(FVector DireccionDisparo)
{
	if (PuedeDisparar)
	{
		FVector PosicionDisparo = GetActorLocation() + DireccionDisparo * 100.0f;
		FRotator RotacionDisparo = DireccionDisparo.Rotation();
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			AGalagaProjectile* Proyectil = World->SpawnActor<AGalagaProjectile>(PosicionDisparo, RotacionDisparo);
			if (Proyectil)
			{
				Proyectil->SetOwner(this);
			}
		}
	}

}

void AMiniNaveEnemigaEspia01::Disparo()
{
	if (PuedeDisparar)
	{
		AGalagaPawn* avatar = Cast<AGalagaPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		
		if (!avatar)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se encontro el avatar"));
			return;

		}

		FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
		FVector DireccionDisparo = FVector(0.0f, -1.0f, 0.0f);

		Disparar(toPlayer);

	}


}

