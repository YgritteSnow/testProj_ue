// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "testCharacter.generated.h"

UCLASS()
class TEST2_API AtestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AtestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);

	bool m_isRMousePressed = true;
	void LookUp(float value);
	void LookRight(float value);

	void JumpStart();
	void JumpStop();
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* m_camera;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* m_skeletal;
};
