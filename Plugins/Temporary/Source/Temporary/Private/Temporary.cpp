#include "Temporary.h"

#include "Logging/LogMacros.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogTemporary, Log, All);

void FTemporaryModule::StartupModule()
{
	UE_LOG(LogTemporary, Log, TEXT("Temporary plugin module started"));
}

void FTemporaryModule::ShutdownModule()
{
	UE_LOG(LogTemporary, Log, TEXT("Temporary plugin module stopped"));
}

IMPLEMENT_MODULE(FTemporaryModule, Temporary);
