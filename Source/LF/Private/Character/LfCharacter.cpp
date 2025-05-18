// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LfCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

ALfCharacter::ALfCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
}
