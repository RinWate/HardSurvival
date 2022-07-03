// Copyright Epic Games, Inc. All Rights Reserved.

#include "HardSurvival.h"

#include "Internationalization/StringTableRegistry.h"
#include "Modules/ModuleManager.h"


void FHardSurvival::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	LOCTABLE_FROMFILE_GAME("UIStrings", "RU", "Localization/RU-ru.csv");
}

void FHardSurvival::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();
}

IMPLEMENT_PRIMARY_GAME_MODULE(FHardSurvival, HardSurvival, "HardSurvival");
