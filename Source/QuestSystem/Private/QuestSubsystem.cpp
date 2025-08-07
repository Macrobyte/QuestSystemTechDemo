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
	
	UE_LOG(LogTemp, Warning, TEXT("Accepting Quest: %s for Bearer: %s from Giver: %s"), 
		*Quest->Title.ToString(), 
		*Bearer->GetOwner()->GetActorLabel(), 
		*Giver->GetOwner()->GetActorLabel());
	
	QuestInstance.Quest->bIsActive = true;

	for (auto Objective : QuestInstance.Quest->Objectives)
	{
		UQuestObjectiveBase* ObjectiveInstance = NewObject<UQuestObjectiveBase>(this, Objective);
		ObjectiveInstance->Initialize(QuestInstance.Quest);
	}
	
	ActiveQuests.Add(QuestInstance.Quest->QuestTag, QuestInstance);

	Bearer->AcceptedQuests.Add(QuestInstance.Quest);

	OnQuestAccepted.Broadcast(QuestInstance.Quest, QuestInstance.Bearer, QuestInstance.Giver);
}

void UQuestSubsystem::HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message)
{
	
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
