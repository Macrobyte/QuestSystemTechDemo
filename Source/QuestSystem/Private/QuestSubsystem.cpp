// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"
#include "QuestBase.h"
#include "QuestEventMessage.h"

void UQuestSubsystem::AcceptQuest(UQuestBase* Quest, UQuestBearer* Bearer, UQuestGiver* Giver)
{
	FQuestInstance QuestInstance;
	QuestInstance.Quest = Quest;
	QuestInstance.Bearer = Bearer;
	QuestInstance.Giver = Giver;
	
	ActiveQuests.Add(QuestInstance.Quest->QuestTag, QuestInstance);

	QuestInstance.Quest->bIsActive = true;

	OnQuestAccepted.Broadcast(QuestInstance.Quest, QuestInstance.Bearer, QuestInstance.Giver);
	
}

void UQuestSubsystem::HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message)
{
	
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
