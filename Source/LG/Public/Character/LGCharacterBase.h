// Copyright xiao xiong

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LGCharacterBase.generated.h"

UCLASS(Abstract)
class LG_API ALGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ALGCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
