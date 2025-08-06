// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestStatusBillboard.h"



UQuestStatusBillboard::UQuestStatusBillboard()
{
	QuestIcon = nullptr;
	QuestCompleteIcon = nullptr;

	SetHiddenInGame(false);

	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;

	
}

void UQuestStatusBillboard::SetQuestIcon(EQuestMarker Icon)
{
	UTexture2D* NewIcon = nullptr;
	
	switch (Icon)
	{
		case Quest:
			NewIcon = QuestIcon;
		break;
		case QuestComplete:
			NewIcon = QuestCompleteIcon;
		break;
		default:
		break;
	}
	
	SetSprite(NewIcon);

	MarkRenderStateDirty();
}

void UQuestStatusBillboard::BeginPlay()
{
	Super::BeginPlay();
	
	BillboardStartPositionZ = GetRelativeLocation().Z;

	SetComponentTickEnabled(true);
}

void UQuestStatusBillboard::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (bIsAnimated)
		BobBillboard();
}

void UQuestStatusBillboard::BobBillboard()
{
	float newLocationZ = BillboardStartPositionZ + FMath::Sin(BillboardBobbingSpeed * GetWorld()->GetTimeSeconds()) * BillboardBobbingHeight;
	
	SetRelativeLocation(FVector(GetRelativeLocation().X, GetRelativeLocation().Y, newLocationZ));
}
