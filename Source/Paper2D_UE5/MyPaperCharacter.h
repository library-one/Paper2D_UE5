// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "InputActionValue.h"
#include "PaperCharacter.h" // paper2D
//#include "PaperFlipbook.h"

//#include "Camera/CameraComponent.h"
//#include "GameFramework/SpringArmComponent.h"

//#include "GameFramework/CharacterMovementComponent.h"

#include "MyPaperCharacter.generated.h"

class UPaperFlipbook;
class USpringArmComponent;
class UCameraComponent;
class UCharacterMovementComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;



/**
 * 
 */
UCLASS()
class PAPER2D_UE5_API AMyPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMyPaperCharacter();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	virtual void Jump() override;
	virtual void StopJumping() override;


public:
	void Walk(const FInputActionValue& Value);

	//���� Input �̺�Ʈ
	void Attack(const FInputActionValue& Value);

	

	UFUNCTION()
	void OnAttackFinished();

	void UpdateCharacter();

	void UpdateAnimation();

private:

	// Flipbook Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Walk;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Run;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Attack01;


	// Movement state
	bool bIsAttacking;
	FVector2D MovementInput;

	// ī�޶�� Spring Arm Components ��  �߰���.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCharacterMovementComponent> Movement;
	
};
