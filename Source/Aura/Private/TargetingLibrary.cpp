#include "TargetingLibrary.h"
#include "Kismet/GameplayStatics.h"
#include <cfloat>

AActor* UTargetingLibrary::GetNearestTarget(AActor* Requestor, TSubclassOf<AActor> TargetClass)
{
    if (!Requestor || !TargetClass)
    {
        return nullptr;
    }

    UWorld* World = Requestor->GetWorld();
    if (!World)
    {
        return nullptr;
    }

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(World, TargetClass, FoundActors);

    AActor* ClosestActor = nullptr;
    float MinDistSq = FLT_MAX;

    const FVector RequestorLocation = Requestor->GetActorLocation();

    for (AActor* Actor : FoundActors)
    {
        const float DistSq = FVector::DistSquared(RequestorLocation, Actor->GetActorLocation());
        if (DistSq < MinDistSq)
        {
            MinDistSq = DistSq;
            ClosestActor = Actor;
        }
    }

    return ClosestActor;
}
