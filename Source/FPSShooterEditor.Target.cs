// FPSShooter

using UnrealBuildTool;
using System.Collections.Generic;

public class FPSShooterEditorTarget : TargetRules
{
	public FPSShooterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "FPSShooter" } );
	}
}
