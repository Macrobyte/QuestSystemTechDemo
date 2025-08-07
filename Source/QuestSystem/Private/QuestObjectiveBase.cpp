// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestObjectiveBase.h"

DEFINE_LOG_CATEGORY(LogQuestObjective);

void UQuestObjectiveBase::Initialize(UQuestBase* Quest)
{
	OwningQuest = Quest;
}

void UQuestObjectiveBase::HandleMessage(const FQuestEventMessage& Message)
{
}

