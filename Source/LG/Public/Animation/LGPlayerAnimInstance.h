// Copyright xiao xiong

#pragma once

#include "CoreMinimal.h"
#include "Animation/LGAnimInstance.h"
#include "LGPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LG_API ULGPlayerAnimInstance : public ULGAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly)
	ACharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* CharacterMovementComponent;
	
	UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;

};
