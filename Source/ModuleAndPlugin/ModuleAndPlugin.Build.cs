// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ModuleAndPlugin : ModuleRules
{
	public ModuleAndPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		// TestActor는 이 모듈의 cpp 파일에서만 사용하므로 Private 의존성으로 연결합니다.
		PrivateDependencyModuleNames.Add("Test");
	}
}
