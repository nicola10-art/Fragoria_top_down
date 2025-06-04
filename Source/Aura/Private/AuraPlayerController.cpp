#include "AuraPlayerController.h"
#include "TargetingLibrary.h"
#include "InputCoreTypes.h"

AAuraPlayerController::AAuraPlayerController()
{
    CurrentTarget = nullptr;
}

void AAuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindKey(EKeys::Tab, IE_Pressed, this, &AAuraPlayerController::SelectNearestTarget);
    }
}

void AAuraPlayerController::SelectNearestTarget()
{
    AActor* Requestor = GetPawn() ? GetPawn() : Cast<AActor>(this);
    CurrentTarget = UTargetingLibrary::GetNearestTarget(Requestor, TargetClass);
}
