#include "AS_CharacterAttributes.h"
#include "Net/UnrealNetwork.h"

UAS_CharacterAttributes::UAS_CharacterAttributes()
{
    // Set some sensible defaults so designers have values to work with immediately.
    MaxHealth = 100.0f;
    Health = MaxHealth;
    Mana = 100.0f;
}

void UAS_CharacterAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UAS_CharacterAttributes, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAS_CharacterAttributes, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAS_CharacterAttributes, Mana, COND_None, REPNOTIFY_Always);
}

void UAS_CharacterAttributes::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_CharacterAttributes, Health, OldHealth);
}

void UAS_CharacterAttributes::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_CharacterAttributes, MaxHealth, OldMaxHealth);
}

void UAS_CharacterAttributes::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAS_CharacterAttributes, Mana, OldMana);
}
