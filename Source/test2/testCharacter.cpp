// Fill out your copyright notice in the Description page of Project Settings.

#include "testCharacter.h"
#include "test2.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values
AtestCharacter::AtestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("testCamera"));
	m_camera->SetupAttachment(GetCapsuleComponent());
	m_camera->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	m_camera->bUsePawnControlRotation = true;

	m_skeletal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("testSkeletal"));
	m_skeletal->SetupAttachment(m_camera);
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
	AddControllerPitchInput(value);
}

void AtestCharacter::LookRight(float value)
{
	AddControllerYawInput(value);
}

void AtestCharacter::JumpStart()
{
	bPressedJump = true;
}

void AtestCharacter::JumpStop()
{
	bPressedJump = false;
}