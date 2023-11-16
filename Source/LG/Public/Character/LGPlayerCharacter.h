// Copyright xiao xiong

#pragma once

#include "CoreMinimal.h"
#include "Character/LGCharacterBase.h"
#include "LGPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class LG_API ALGPlayerCharacter : public ALGCharacterBase
{
	GENERATED_BODY()
public:
	ALGPlayerCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};
