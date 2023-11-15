// Copyright xiao xiong


#include "Character/LGCharacterBase.h"


ALGCharacterBase::ALGCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ALGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

