// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tutorials : ModuleRules
{
	public Tutorials(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "CommonUI" });

		PrivateDependencyModuleNames.AddRange(new string[] { "MyPlugin" });
	}
}
