// Fill out your copyright notice in the Description page of Project Settings.

#include "PingObjective.h"
#include "QuestBase.h"


void UPingObjective::Initialize(UQuestBase* Quest)
{
	Super::Initialize(Quest);

	UE_LOG(LogQuestObjective, Warning, TEXT("Ping Objective Initialized: %s"), *Quest->Title.ToString());
}

void UPingObjective::HandleMessage(const FQuestEventMessage& Message)
{
	Super::HandleMessage(Message);

	if (Message.ObjectiveTag == TriggerTag)
		bIsCompleted = true;
}

bool UPingObjective::IsComplete() const
{
	return bIsCompleted;
}
