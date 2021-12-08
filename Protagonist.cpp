// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "Protagonist.h"
#include "GameFramework/Actor.h"
#include "Hand.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProtagonist::AProtagonist()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HandSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Hand Spawn Point"));
	HandSpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProtagonist::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AProtagonist::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProtagonist::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	

	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AProtagonist::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AProtagonist::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Manifest"), EInputEvent::IE_Pressed, this, &AProtagonist::Manifest);
	PlayerInputComponent->BindAction(TEXT("Dismiss"), EInputEvent::IE_Released, this, &AProtagonist::Dismiss);



	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AProtagonist::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, & AProtagonist::LookRightRate);

}

void AProtagonist::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}
void AProtagonist::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AProtagonist::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AProtagonist::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}


void AProtagonist::Manifest()
{
	UE_LOG(LogTemp, Warning, TEXT("Hand Spawn"));
	FVector Location = HandSpawnPoint->GetComponentLocation();
	FRotator Rotation = HandSpawnPoint->GetComponentRotation();

	AHand* Hand = GetWorld()->SpawnActor<AHand>(HandClass, Location, Rotation);


	//Hand->SetOwner(this);
}

void AProtagonist::Dismiss()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), HandClass, FoundActors);
	for (AActor* ActorFound : FoundActors)
	{
		ActorFound->Destroy();
	}
}