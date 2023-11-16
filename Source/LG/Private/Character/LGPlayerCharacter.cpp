// Copyright xiao xiong


#include "Character/LGPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/LGPlayerState.h"

ALGPlayerCharacter::ALGPlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ALGPlayerCharacter::InitAbilityActorInfo()
{
	ALGPlayerState* LGPlayerState = GetPlayerState<ALGPlayerState>();
	check(LGPlayerState);
	AbilitySystemComponent = LGPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(LGPlayerState,this);
	AttributeSet = LGPlayerState->GetAttributeSet();
}

void ALGPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// Init ability actor info for the server, because we don't have Controller in simulated proxy.
	InitAbilityActorInfo();
}

void ALGPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// init ability info for client
	InitAbilityActorInfo();
}
