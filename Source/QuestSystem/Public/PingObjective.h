// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestObjectiveBase.h"
#include "PingObjective.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew)
class QUESTSYSTEM_API UPingObjective : public UQuestObjectiveBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Objective")
	FGameplayTag TriggerTag;

	UPROPERTY()
	bool bIsCompleted = false;

public:
virtual void Initialize(UQuestBase* Quest) override;
	
	virtual void HandleMessage(const FQuestEventMessage& Message) override;

	virtual bool IsComplete() const override;
	
};
