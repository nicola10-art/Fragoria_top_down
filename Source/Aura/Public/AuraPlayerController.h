#pragma once

#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

/**
 * PlayerController that selects the nearest target when TAB is pressed.
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AAuraPlayerController();

    virtual void SetupInputComponent() override;

    /** Class of actors considered as valid targets */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Targeting")
    TSubclassOf<AActor> TargetClass;

    /** Currently selected target */
    UPROPERTY(BlueprintReadOnly, Category="Targeting")
    AActor* CurrentTarget;

    /** Finds the nearest target and stores it in CurrentTarget */
    UFUNCTION(BlueprintCallable, Category="Targeting")
    void SelectNearestTarget();
};
