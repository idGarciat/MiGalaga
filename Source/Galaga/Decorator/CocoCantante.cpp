// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoCantante.h"

void ACocoCantante::BeginPlay()
{
    Super::BeginPlay();
    Radius = 500.0f;
    Center = GetActorLocation();
}

void ACocoCantante::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

float ACocoCantante::Recibirdano()
{
	return Super::Recibirdano() + 10;
}

void ACocoCantante::Tanier()
{
	Super::Tanier();

}

void ACocoCantante::Pelear()
{
	Super::Pelear();

}

void ACocoCantante::Afinar()
{
	Super::Afinar();

}

void ACocoCantante::SetMesh()
{
	Super::SetMesh();


}

TArray<AActor*> ACocoCantante::GetActorsInSphere()
{
	Super::GetActorsInSphere();



    UE_LOG(LogTemp, Warning, TEXT("Esfera del coco cantante"));

    UWorld* World = GetWorld();
    Center = GetActorLocation();

    OverlappingActors.Empty();

    //TArray<AActor*> OverlappingActors;
    TArray<FOverlapResult> OverlapResults;

    // Configurar parámetros de colisión
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this);  // Ignorar actor específico si es necesario
    CollisionParams.bTraceComplex = false;
    CollisionParams.bReturnPhysicalMaterial = false;

    // Definir la forma y tamaño del área de superposición
    FCollisionShape CollisionShape;
    CollisionShape.SetSphere(Radius);

    // Realizar la consulta de superposición
    bool bOverlap = World->OverlapMultiByObjectType(
        OverlapResults,
        Center,
        FQuat::Identity,
        FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllDynamicObjects),
        CollisionShape,
        CollisionParams
    );

    // Si hubo superposición, agregar actores a la lista
    if (bOverlap)
    {

        for (auto& OverlapResult : OverlapResults)
        {
            AActor* OverlappedActor = OverlapResult.GetActor();
            if (OverlappedActor)
            {

                OverlappingActors.Add(OverlappedActor);
            }
        }
    }

    // (Opcional) Dibujar la esfera para depuración
    DrawDebugSphere(World, Center, Radius, 32, FColor::Green, false, 3.0f);


    UE_LOG(LogTemp, Warning, TEXT("Number of Actors in Sphere: %d from CocoCantante"), OverlappingActors.Num());
    for (int i = 0; i < OverlappingActors.Num(); i++)
    {
        UE_LOG(LogTemp, Warning, TEXT("Actors in Sphere: %s from CocoCantante"), *OverlappingActors[i]->GetName());
    }
    return OverlappingActors;
}
