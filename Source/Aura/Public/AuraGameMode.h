#pragma once

#include "GameFramework/GameModeBase.h"
#include "AuraGameMode.generated.h"

/**\n * Game mode that uses AAuraPlayerController by default.\n */
UCLASS()
class AURA_API AAuraGameMode : public AGameModeBase
{
    GENERATED_BODY()
public:
    AAuraGameMode();
};
