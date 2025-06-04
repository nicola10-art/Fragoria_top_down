#include "AuraGameMode.h"
#include "AuraPlayerController.h"

AAuraGameMode::AAuraGameMode()
{
    PlayerControllerClass = AAuraPlayerController::StaticClass();
}
