using UnrealBuildTool;

public class Temporary : ModuleRules
{
	public Temporary(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// 플러그인의 공개 헤더와 런타임 코드에서 사용할 엔진 모듈입니다.
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine"
			}
		);
	}
}
