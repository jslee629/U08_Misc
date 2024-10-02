#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IAssetTypeActions;
class FExtender;
class FToolBarBuilder;

class FToreModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void AddLoadMeshButton(FToolBarBuilder& ToolBarBuilder);

private:
	TSharedPtr<IAssetTypeActions> AssetToolAction;
	TSharedPtr<FExtender> Extender;
};
