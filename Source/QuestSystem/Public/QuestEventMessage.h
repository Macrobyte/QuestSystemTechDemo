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

	// The actor that triggered the event can be null if not applicable
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	AActor* Instigator;

	// Can be the NPC you interact with or enemy you defeat, etc...
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	AActor* Target;

	// Additional data related to the event. For events that can count (e.g., defeating enemies, collecting items)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Quest")
	int32 Count = 1;
};
