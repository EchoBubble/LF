// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LFCharacterBase.h"

// Sets default values
ALFCharacterBase::ALFCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName(TEXT("WeaponHandSocket")));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


void ALFCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



