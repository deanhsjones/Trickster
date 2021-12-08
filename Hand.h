// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Hand.generated.h"

UCLASS()
class TRICKSTER_API AHand : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* HandMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"));
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"));
	class UCameraComponent* Camera;


	void MoveForward(float AxisValue);
	/*void LookRight(float AxisValue);*/
	void MoveRight(float AxisValue);
	void MoveUp(float AxisValue);

	/*void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);*/

	void Turn(float Value);
	void Pitch(float Value);
	void Roll(float Value);

	UPROPERTY(EditAnywhere)
		float RotationRate = 30;

};
