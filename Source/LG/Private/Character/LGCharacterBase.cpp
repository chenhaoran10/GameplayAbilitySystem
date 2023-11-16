// Copyright xiao xiong


#include "Character/LGCharacterBase.h"


ALGCharacterBase::ALGCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ALGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

