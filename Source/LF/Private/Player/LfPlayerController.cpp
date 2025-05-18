// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LfPlayerController.h"
#include "EnhancedInputSubsystems.h"


ALfPlayerController::ALfPlayerController()
{
	bReplicates = true;
	
}

void ALfPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(LfContext)

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem)
	Subsystem->AddMappingContext(LfContext,0);
	bShowMouseCursor = false;
	
	
}

void ALfPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ALfPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ALfPlayerController::Look);
}

void ALfPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ALfPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	//AddPitchInput(LookAxisVector.Y);没有限制

	const FRotator ControllerRotation = GetControlRotation();
	float NewPitch = ControllerRotation.Pitch + LookAxisVector.Y;
	NewPitch = FMath::ClampAngle(NewPitch, -60.0f, 45.0f);
	//手动限制角度得用SetControlRotation
	SetControlRotation(FRotator(NewPitch, ControllerRotation.Yaw, ControllerRotation.Roll));
}
