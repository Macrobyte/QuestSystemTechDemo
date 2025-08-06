// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestBearer.generated.h"


class UQuestBase;

UCLASS( ClassGroup=(QuestSystem), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestBearer : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQuestBearer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UQuestBase*> AcceptedQuests;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
