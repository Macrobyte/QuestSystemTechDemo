// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BillboardComponent.h"
#include "QuestStatusBillboard.generated.h"

UENUM()
enum EQuestMarker
{
	Quest,
	QuestComplete,
};

UCLASS( ClassGroup=(QuestSystem), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestStatusBillboard : public UBillboardComponent
{
	GENERATED_BODY()

public:
	UQuestStatusBillboard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestStatusBillboard|Animation")
	bool bIsAnimated = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestStatusBillboard|Animation")
	float BillboardBobbingSpeed = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestStatusBillboard|Animation")
	float BillboardBobbingHeight = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "QuestStatusBillboard", meta=(DisplayPriority=1))
	UTexture2D* QuestIcon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "QuestStatusBillboard", meta=(DisplayPriority=1))
	UTexture2D* QuestCompleteIcon;
	
	UFUNCTION(BlueprintCallable, Category = "Quest Status Billboard")
	void SetQuestIcon(EQuestMarker Icon);

protected:
	virtual void BeginPlay() override;

private:

	float BillboardStartPositionZ;
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void BobBillboard();
	
};
