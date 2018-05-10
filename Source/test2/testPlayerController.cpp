// Fill out your copyright notice in the Description page of Project Settings.

#include "testPlayerController.h"

void AtestPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameAndUI());
}