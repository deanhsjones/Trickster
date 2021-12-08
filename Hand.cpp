// Fill out your copyright notice in the Description page of Project Settings.


#include "Hand.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHand::AHand()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	HandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hand Mesh"));
	HandMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	//add camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void AHand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHand::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("HandMoveForward"), this, &AHand::MoveForward);
	/*PlayerInputComponent->BindAxis(TEXT("HandLookUp"), this, &APawn::AddControllerPitchInput);*/
	PlayerInputComponent->BindAxis(TEXT("HandPitchUp"), this, &AHand::Pitch);
	PlayerInputComponent->BindAxis(TEXT("HandMoveRight"), this, &AHand::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("HandMoveUp"), this, &AHand::MoveUp);
	/*PlayerInputComponent->BindAxis(TEXT("HandLookRight"), this, &APawn::AddControllerYawInput);*/
	PlayerInputComponent->BindAxis(TEXT("HandYawRight"), this, &AHand::Turn);
	PlayerInputComponent->BindAxis(TEXT("HandRollRight"), this, &AHand::Roll);
	

	/*PlayerInputComponent->BindAxis(TEXT("HandLookUpRate"), this, &AHand::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("HandLookRightRate"), this, &AHand::LookRightRate);*/

}

void AHand::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}
void AHand::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AHand::MoveUp(float AxisValue)
{
	AddMovementInput(GetActorUpVector() * AxisValue);
}



//void AHand::LookUpRate(float AxisValue)
//{
//	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
//}

//void AHand::LookRightRate(float AxisValue)
//{
//	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
//}

void AHand::Turn(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}


void AHand::Pitch(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Pitch = Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}

void AHand::Roll(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Roll = Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}
