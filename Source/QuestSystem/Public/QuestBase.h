// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestObjectiveBase.h"
#include "Engine/DataAsset.h"
#include "QuestBase.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FGameplayTag QuestTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	TArray<TSubclassOf<UQuestObjectiveBase>> Objectives;

	UPROPERTY(VisibleAnywhere, Category = "State")
	bool bIsActive = false;

public:

	virtual void StartQuest();
	virtual void CompleteQuest();
	
};
