// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPSShooter : ModuleRules
{
	public FPSShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput",
		"HTTP", "Json", "UMG", "Slate", "SlateCore", "JsonUtilities" });
	}
}
