// Copyright xiao xiong


#include "AbilitySystem/LGAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

ULGAttributeSet::ULGAttributeSet()
{
}

void ULGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// REP_NOTIFY_Always means it will rep to client even the same value
	DOREPLIFETIME_CONDITION_NOTIFY(ULGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULGAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULGAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void ULGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	// Call Ability system to do some thing.
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULGAttributeSet, Health, OldHealth);
}

void ULGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULGAttributeSet, MaxHealth, OldMaxHealth);
}

void ULGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULGAttributeSet, Mana, OldMana);
}

void ULGAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULGAttributeSet, MaxMana, OldMaxMana);
}
