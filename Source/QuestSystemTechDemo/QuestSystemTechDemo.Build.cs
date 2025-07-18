// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QuestSystemTechDemo : ModuleRules
{
	public QuestSystemTechDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayMessageRuntime" });
	}
}
