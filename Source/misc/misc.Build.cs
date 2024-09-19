using UnrealBuildTool;

public class misc : ModuleRules
{
	public misc(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"ProceduralMeshComponent",
			"AIModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
