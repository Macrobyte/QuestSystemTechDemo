// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestGiver.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogQuestSystem, Warning, All);

class UQuestBearer;
class UQuestBase;

UCLASS( ClassGroup=(QuestSystem), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestGiver : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQuestGiver();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UQuestBase* ActiveQuest = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UQuestBase* > Quests;
	
	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool GiveQuest(UQuestBearer* QuestBearer);

	UFUNCTION(BlueprintCallable, Category = "Quest")
	UQuestBase* GetFirstQuest() const;
	
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void UnlockNextQuest(UQuestBase* Quest);
	
		
};


