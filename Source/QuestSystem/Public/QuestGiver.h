// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestGiver.generated.h"

class UQuestBearer;
class UQuestBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestGiver : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQuestGiver();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UQuestBase* ActiveQuest = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UQuestBase* > Quests;

	// When player accepts a quest give them the next quest in the list.
	// In UI this will be a button to accept the quest.
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void GiveQuest(UQuestBearer* QuestBearer);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void UnlockNextQuest(UQuestBase* Quest);
	
		
};


