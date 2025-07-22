// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"
#include "QuestBase.h"
#include "QuestEventMessage.h"

void UQuestSubsystem::AcceptQuest(UQuestBase* Quest)
{
	
}

void UQuestSubsystem::CompleteQuest(UQuestBase* Quest)
{
}

void UQuestSubsystem::TrackQuest(UQuestBase* Quest)
{
	
}

void UQuestSubsystem::UntrackQuest(UQuestBase* Quest)
{
}

void UQuestSubsystem::HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message)
{
	if (UQuestBase** QuestPtr = ActiveQuests.Find(Channel))
	{
		if (UQuestBase* Quest = *QuestPtr)
		{
			// TODO -  Finish later
		}
	}
}

void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Get the gameplay message subsystem
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	
	ListenerHandle = MessageSubsystem.RegisterListener<FQuestEventMessage>(
		FGameplayTag::RequestGameplayTag(FName("Quest.Event")),
		[this](const FGameplayTag& Channel, const FQuestEventMessage& Message)
		{
			HandleQuestEvent(Channel, Message);
		}
	);
}

void UQuestSubsystem::Deinitialize()
{
	if (ListenerHandle.IsValid())
	{
		UGameplayMessageSubsystem& MsgSys = UGameplayMessageSubsystem::Get(this);
		MsgSys.UnregisterListener(ListenerHandle);
		ListenerHandle = FGameplayMessageListenerHandle();
	}

	Super::Deinitialize();
}
