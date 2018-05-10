// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "test2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEST2_API Atest2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()


		virtual void StartPlay() override;

	UFUNCTION(BlueprintCallable)
		void ChangeUserWidget(TSubclassOf<UUserWidget> widget);

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> m_startWidget;

	UPROPERTY(VisibleAnywhere)
	UUserWidget* m_curWidget;
	
};
