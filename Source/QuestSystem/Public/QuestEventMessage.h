// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestEventMessage.generated.h"

USTRUCT(BlueprintType)
struct QUESTSYSTEM_API FQuestEventMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	FGameplayTag QuestTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	FGameplayTag ObjectiveTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	AActor* Instigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	int32 Count = 1;
};
