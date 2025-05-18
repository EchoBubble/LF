// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LfCharacterBase.h"

// Sets default values
ALfCharacterBase::ALfCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName(TEXT("WeaponHandSocket")));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


void ALfCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



