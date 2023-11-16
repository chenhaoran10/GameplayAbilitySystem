// Copyright xiao xiong


#include "Character/LGEnemy.h"

#include "AbilitySystem/LGAbilitySystemComponent.h"
#include "AbilitySystem/LGAttributeSet.h"

ALGEnemy::ALGEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULGAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<ULGAttributeSet>("AttributeSet");	
}

void ALGEnemy::HighLightActor()
{
	bIsHighlight = true;
}

void ALGEnemy::UnHighLightActor()
{
	bIsHighlight = false;
}
