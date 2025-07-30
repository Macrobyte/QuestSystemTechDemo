// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestBearer.h"

#include "QuestBase.h"

// Sets default values for this component's properties
UQuestBearer::UQuestBearer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UQuestBearer::BeginPlay()
{
	Super::BeginPlay();

	FString Message = FString::Printf(TEXT("QuestBearer Component Initialized: %s"), *GetOwner()->GetActorLabel());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);
}


void UQuestBearer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

