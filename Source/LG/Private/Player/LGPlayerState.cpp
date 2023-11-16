// Copyright xiao xiong


#include "Player/LGPlayerState.h"

#include "AbilitySystem/LGAbilitySystemComponent.h"
#include "AbilitySystem/LGAttributeSet.h"

ALGPlayerState::ALGPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<ULGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<ULGAttributeSet>("AttributeSet");	
}

UAbilitySystemComponent* ALGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
