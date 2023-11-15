// Copyright xiao xiong

#pragma once

#include "CoreMinimal.h"
#include "Animation/LGAnimInstance.h"
#include "LGEnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LG_API ULGEnemyAnimInstance : public ULGAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly)
	ACharacter* EnemyCharacter;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* CharacterMovementComponent;
	
	UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;

};
