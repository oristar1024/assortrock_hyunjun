// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BaseLevelMode.generated.h"

/**
 * 
 */
UCLASS()
class UE_PRACTICE_API ABaseLevelMode : public AGameMode
{
	GENERATED_BODY()

	ABaseLevelMode();

	void BeginPlay() override;
};
