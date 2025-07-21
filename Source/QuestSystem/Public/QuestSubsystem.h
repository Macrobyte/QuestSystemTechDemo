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
	void AddQuest(UQuestBase* Quest);

	void RemoveQuest(UQuestBase* Quest);
	
	void HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message);

	

private:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY()
	TMap<FGameplayTag, UQuestBase*> ActiveQuests;

	FGameplayMessageListenerHandle ListenerHandle;
	
};
