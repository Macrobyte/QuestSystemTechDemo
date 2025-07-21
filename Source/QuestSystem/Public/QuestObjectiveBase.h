// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestEventMessage.h"
#include "QuestObjectiveBase.generated.h"

class UQuestBase;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestObjectiveBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Objective")
	FGameplayTag ObjectiveTag;

	virtual void Initialize(UQuestBase* Quest);
	virtual void HandleMessage(const FQuestEventMessage& Message);
	virtual bool IsComplete() const;
};
