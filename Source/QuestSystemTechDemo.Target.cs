// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class QuestSystemTechDemoTarget : TargetRules
{
	public QuestSystemTechDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("QuestSystemTechDemo");
		ExtraModuleNames.Add("GameplayMessageRuntime");
		ExtraModuleNames.Add("QuestSystem");
	}
	
}
