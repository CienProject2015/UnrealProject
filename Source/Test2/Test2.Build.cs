// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test2 : ModuleRules
{
	public Test2(TargetInfo Target)
	{
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
