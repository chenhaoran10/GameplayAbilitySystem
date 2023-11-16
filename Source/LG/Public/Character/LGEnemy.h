// Copyright xiao xiong

#pragma once

#include "CoreMinimal.h"
#include "Character/LGCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "LGEnemy.generated.h"

/**
 * 
 */
UCLASS()
class LG_API ALGEnemy : public ALGCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	ALGEnemy();

	/** Enemy Interface */
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/** end Enemy Interface */
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsHighlight;

protected:
	virtual void BeginPlay() override;
};
