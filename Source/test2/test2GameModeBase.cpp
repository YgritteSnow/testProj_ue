// Fill out your copyright notice in the Description page of Project Settings.

#include "test2GameModeBase.h"
#include "Engine/Engine.h"

void Atest2GameModeBase::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("GameMode:StartPlay"));
	}
}


