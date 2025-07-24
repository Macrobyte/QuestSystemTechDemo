// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGiver.h"

#include "QuestBase.h"
#include "QuestBearer.h"
#include "QuestSubsystem.h"

// Sets default values for this component's properties
UQuestGiver::UQuestGiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


void UQuestGiver::GiveQuest(UQuestBearer* QuestBearer)
{
	if (Quests.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No quests available to give."));
		return; // No quests to give
	}

	UQuestBase* Quest = Quests[0]; // Get the first quest entry in the list
	
	if (ActiveQuest == Quest)
	{
		UE_LOG(LogTemp, Warning, TEXT("Quest %s is already active."), *Quest->Title.ToString());
		return; // If the quest is already active, do not give it again.
	}
	
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UQuestSubsystem* QuestSubsystem = GameInstance->GetSubsystem<UQuestSubsystem>();

	ActiveQuest = Quest;

	QuestSubsystem->AcceptQuest(Quest, QuestBearer, this);
}

void UQuestGiver::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("QuestGiver Component Initialized!"));
}


void UQuestGiver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UQuestGiver::UnlockNextQuest(UQuestBase* Quest)
{
	if (Quests.Num() > 0)
	{
		Quests.RemoveAt(0); // Remove the first quest from the list
	}
}

