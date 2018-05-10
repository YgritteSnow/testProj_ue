// Fill out your copyright notice in the Description page of Project Settings.

#include "test2GameModeBase.h"
#include "Engine/Engine.h"
#include "Blueprint/UserWidget.h"

void Atest2GameModeBase::StartPlay()
{
	Super::StartPlay();
	m_curWidget = nullptr;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("GameMode:StartPlay"));
	}

	ChangeUserWidget(m_startWidget);
}


void Atest2GameModeBase::ChangeUserWidget(TSubclassOf<UUserWidget> widget)
{
	if (m_curWidget != nullptr)
	{
		m_curWidget->RemoveFromViewport();
		//m_curWidget->BeginDestroy();
		m_curWidget = nullptr;
	}

	if (widget != nullptr)
	{
		m_curWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
		if (m_curWidget != nullptr)
		{
			m_curWidget->AddToViewport();
		}
	}
}