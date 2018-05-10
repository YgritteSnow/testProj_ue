// Fill out your copyright notice in the Description page of Project Settings.

#include "testCharacter.h"
#include "test2.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AtestCharacter::AtestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("arm!"));
	m_springArm->SetupAttachment(RootComponent);
	m_springArm->SetRelativeLocation(FVector(10, 0, 0));

	m_springArm->TargetArmLength = 200.f;
	m_springArm->bEnableCameraLag = true;
	m_springArm->CameraLagSpeed = 15.f;

	m_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("camera!"));
	m_camera->SetupAttachment(m_springArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AtestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Character:Begin"));
	}
}

// Called every frame
void AtestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator y = GetActorRotation();
	y.Yaw = m_cameraRotation.X;
	y.Pitch = FMath::Clamp(m_cameraRotation.Y, 10.f, 85.f);
	m_springArm->SetWorldRotation(y);
}

// Called to bind functionality to input
void AtestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AtestCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AtestCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AtestCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AtestCharacter::LookRight);

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AtestCharacter::JumpStart);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &AtestCharacter::JumpStop);

	PlayerInputComponent->BindAxis("Zoom", this, &AtestCharacter::Zoom);
}

void AtestCharacter::MoveForward(float value)
{
	FVector wd = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(wd, value);
}

void AtestCharacter::MoveRight(float value)
{
	FVector wd = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(wd, value);
}

void AtestCharacter::LookUp(float value)
{
	m_cameraRotation.Y -= value;
	//AddControllerPitchInput(value);
}

void AtestCharacter::LookRight(float value)
{
	m_cameraRotation.X += value;
	//AddControllerYawInput(value);
}

void AtestCharacter::Zoom(float value)
{
	m_zoomFactor += FMath::Clamp(m_zoomFactor + value, 0.f, 1.f);
	m_springArm->TargetArmLength = FMath::Lerp(zoomMin, zoomMax, m_zoomFactor);
}

void AtestCharacter::JumpStart()
{
	bPressedJump = true;
}

void AtestCharacter::JumpStop()
{
	bPressedJump = false;
}