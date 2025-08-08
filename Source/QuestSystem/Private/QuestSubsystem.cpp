// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"
#include "QuestBase.h"
#include "QuestBearer.h"
#include "QuestEventMessage.h"
#include "QuestGiver.h"

void UQuestSubsystem::AcceptQuest(UQuestBase* Quest, UQuestBearer* Bearer, UQuestGiver* Giver)
{
	FQuestInstance QuestInstance;
	QuestInstance.Quest = Quest;
	QuestInstance.Bearer = Bearer;
	QuestInstance.Giver = Giver;
	
	UE_LOG(LogQuestSystem, Warning, TEXT("Accepting Quest: %s for Bearer: %s from Giver: %s"), 
		*Quest->Title.ToString(), 
		*Bearer->GetOwner()->GetActorLabel(), 
		*Giver->GetOwner()->GetActorLabel());
	
	QuestInstance.Quest->bIsActive = true;

	for (auto Objective : QuestInstance.Quest->Objectives)
	{
		UQuestObjectiveBase* ObjectiveInstance = NewObject<UQuestObjectiveBase>(this, Objective);
		
		ObjectiveInstance->Initialize(QuestInstance.Quest);

		QuestInstance.ActiveObjectiveInstances.Add(ObjectiveInstance);

		UE_LOG(LogQuestSystem, Warning, TEXT("Added objective instance"))
	}
	
	ActiveQuests.Add(QuestInstance.Quest->QuestTag, QuestInstance);

	Bearer->AcceptedQuests.Add(QuestInstance.Quest);

	OnQuestAccepted.Broadcast(QuestInstance.Quest, QuestInstance.Bearer, QuestInstance.Giver);
}

void UQuestSubsystem::HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message)
{
	UE_LOG(LogTemp, Log, TEXT("Received quest event for tag: %s"), *Message.QuestTag.ToString());
	
	FQuestInstance* QuestInstance = ActiveQuests.Find(Channel);

	if (!QuestInstance)
	{
		UE_LOG(LogQuestSystem, Warning, TEXT("No active quest with tag %s"), *Message.QuestTag.ToString());
		return;
	}

	for (UQuestObjectiveBase* Objective : QuestInstance->ActiveObjectiveInstances)
	{
		if (!Objective)
			continue;

		Objective->HandleMessage(Message);
	}

	UE_LOG(LogQuestSystem, Log, TEXT("Handled quest event for quest %s"), *Message.QuestTag.ToString());
}

void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);


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
