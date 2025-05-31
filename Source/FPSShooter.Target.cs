// FPSShooter

using UnrealBuildTool;
using System.Collections.Generic;

public class FPSShooterTarget : TargetRules
{
	public FPSShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "FPSShooter" } );
	}
}
