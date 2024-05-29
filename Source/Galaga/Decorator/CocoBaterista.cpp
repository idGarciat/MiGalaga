// Fill out your copyright notice in the Description page of Project Settings.


#include "CocoBaterista.h"

void ACocoBaterista::BeginPlay()
{
	Super::BeginPlay();
    Radius = 1000.0f;
    Center = GetActorLocation();
}

void ACocoBaterista::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

float ACocoBaterista::Recibirdano()
{
    return Super::Recibirdano() + 5;
}

void ACocoBaterista::Tanier()
{
    Super::Tanier();



}

void ACocoBaterista::Pelear()
{
    Super::Pelear();

}

void ACocoBaterista::Afinar()
{
    Super::Afinar();

}

void ACocoBaterista::SetMesh()
{
    Super::SetMesh();


}

TArray<AActor*> ACocoBaterista::GetActorsInSphere()
{
    Super::GetActorsInSphere();

    UE_LOG(LogTemp, Warning, TEXT("Esfera del coco baterista"));

    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("GetActorsInSphere from CocoBaterista"));   

    UWorld * World = GetWorld();
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
    DrawDebugSphere(World, Center, Radius, 32, FColor::Red, false, 3.0f);


    UE_LOG(LogTemp, Warning, TEXT("Number of Actors in Sphere: %d from CocoBaterista"), OverlappingActors.Num());
    for (int i = 0; i < OverlappingActors.Num(); i++)
    {
        UE_LOG(LogTemp, Warning, TEXT("Actors in Sphere: %s from CocoBaterista"), *OverlappingActors[i]->GetName());
    }
    return OverlappingActors;

}
