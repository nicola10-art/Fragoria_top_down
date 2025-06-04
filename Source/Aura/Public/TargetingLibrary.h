#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TargetingLibrary.generated.h"

UCLASS()
class AURA_API UTargetingLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="Targeting")
    static AActor* GetNearestTarget(AActor* Requestor, TSubclassOf<AActor> TargetClass);
};
