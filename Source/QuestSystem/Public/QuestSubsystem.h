// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestEventMessage.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"



class UQuestGiver;
class UQuestBearer;
class UQuestBase;

/**
 * Represents an instance of a quest, including the quest itself, the bearer (player), and the giver (NPC or QuestBoard).
 */
USTRUCT()
struct FQuestInstance
{
	GENERATED_BODY()

	UPROPERTY()
	UQuestBase* Quest;

	UPROPERTY()
	UQuestBearer* Bearer;

	UPROPERTY()
	UQuestGiver* Giver;
};


UCLASS()
class QUESTSYSTEM_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void AcceptQuest(UQuestBase* Quest, UQuestBearer* Bearer, UQuestGiver* Giver);
	
	void HandleQuestEvent(const FGameplayTag& Channel, const FQuestEventMessage& Message);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestAccepted, UQuestBase*, Quest, UQuestBearer*, Bearer, UQuestGiver*, Giver);
	UPROPERTY(BlueprintAssignable, Category = "Quest Events")
	FOnQuestAccepted OnQuestAccepted;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestCompleted, UQuestBase*, Quest, UQuestBearer*, Bearer, UQuestGiver*, Giver);
	UPROPERTY(BlueprintAssignable, Category = "Quest Events")
	FOnQuestCompleted OnQuestCompleted;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestTurnedIn, UQuestBase*, Quest, UQuestBearer*, Bearer, UQuestGiver*, Giver);
	UPROPERTY(BlueprintAssignable, Category = "Quest Events")
	FOnQuestTurnedIn OnQuestTurnedIn;


	
private:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY()
	TMap<FGameplayTag, FQuestInstance> ActiveQuests;
	
	FGameplayMessageListenerHandle ListenerHandle;
	
};


