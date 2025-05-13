// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LFCharacterBase.generated.h"

UCLASS(Abstract)
class LF_API ALFCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ALFCharacterBase();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
