// Copyright xiao xiong


#include "Animation/LGEnemyAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void ULGEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	EnemyCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (EnemyCharacter)
	{
		CharacterMovementComponent = EnemyCharacter->GetCharacterMovement();
	}
}

void ULGEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!EnemyCharacter||!CharacterMovementComponent)
	{
		return;
	}
	GroundSpeed = CharacterMovementComponent->Velocity.Size2D();
}
