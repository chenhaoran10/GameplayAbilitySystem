// Copyright xiao xiong


#include "Character/LGEnemy.h"

ALGEnemy::ALGEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
	
}

void ALGEnemy::HighLightActor()
{
	bIsHighlight = true;
}

void ALGEnemy::UnHighLightActor()
{
	bIsHighlight = false;
}
