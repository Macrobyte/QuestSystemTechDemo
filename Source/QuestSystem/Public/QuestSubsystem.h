// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestEventMessage.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"


class UQuestBase;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void AcceptQuest(UQuestBase* Quest);
	void CompleteQuest(UQuestBase* Quest);

	// Quest tracking allows players to keep track of active quests. Good for UI and quest log systems.
	void TrackQuest(UQuestBase* Quest);
	void UntrackQuest(UQuestBase* Quest);
	
	void HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message);

private:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY()
	TMap<FGameplayTag, UQuestBase*> ActiveQuests;

	UPROPERTY()
	TSet<UQuestBase*> TrackedQuests;
	
	FGameplayMessageListenerHandle ListenerHandle;
	
};
