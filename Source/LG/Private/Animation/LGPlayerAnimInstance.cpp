// Copyright xiao xiong


#include "Animation/LGPlayerAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void ULGPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	PlayerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (PlayerCharacter)
	{
		CharacterMovementComponent = PlayerCharacter->GetCharacterMovement();
	}
}

void ULGPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!PlayerCharacter||!CharacterMovementComponent)
	{
		return;
	}
	GroundSpeed = CharacterMovementComponent->Velocity.Size2D();
}
