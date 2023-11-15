// Copyright xiao xiong


#include "Player/LGPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Stats/Stats.h"

DECLARE_STATS_GROUP(TEXT("Move"), STATGROUP_Move, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("Move"), STAT_Move, STATGROUP_Move);

ALGPlayerController::ALGPlayerController()
{
	bReplicates = true;
}

void ALGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(LGContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(LGContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ALGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALGPlayerController::Move);
}

void ALGPlayerController::Move(const FInputActionValue& InputActionValue)
{
	SCOPE_CYCLE_COUNTER(STAT_Move);
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

// void ALGPlayerController::Move(const FInputActionValue& InputActionValue)
// {
// 	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
// 	const FRotator Rotation = GetControlRotation();
// 	const float Yaw = FMath::DegreesToRadians(Rotation.Yaw); // 将偏航角从度转换为弧度
//
// 	const FVector ForwardDirection(FMath::Cos(Yaw), FMath::Sin(Yaw), 0.f); // 使用余弦和正弦函数计算前进方向
// 	const FVector RightDirection(-FMath::Sin(Yaw), FMath::Cos(Yaw), 0.f); // 使用余弦和正弦函数计算右侧方向
//
// 	if (APawn* ControlledPawn = GetPawn())
// 	{
// 		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
// 		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
// 	}
// }
//
// void ALGPlayerController::Move(const FInputActionValue& InputActionValue)
// {
// 	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
// 	const FQuat Rotation = GetControlRotation().Quaternion(); // 将控制器的旋转从FRotator转换为FQuat
//
// 	const FVector ForwardDirection = Rotation.RotateVector(FVector::ForwardVector); // 使用FQuat::RotateVector函数将世界空间中的前进方向旋转到控制器的旋转空间中
// 	const FVector RightDirection = Rotation.RotateVector(FVector::RightVector); // 使用FQuat::RotateVector函数将世界空间中的右侧方向旋转到控制器的旋转空间中
//
// 	if (APawn* ControlledPawn = GetPawn())
// 	{
// 		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
// 		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
// 	}
// }
