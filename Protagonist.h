// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Protagonist.generated.h"

UCLASS()
class TRICKSTER_API AProtagonist : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AProtagonist();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Manifest();
	void Dismiss();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

private:

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComp;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* HandSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		TSubclassOf<class AHand> HandClass;

	void MoveForward(float AxisValue);
	void LookRight(float AxisValue);
	void MoveRight(float AxisValue);

	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
		float RotationRate = 30;

};
