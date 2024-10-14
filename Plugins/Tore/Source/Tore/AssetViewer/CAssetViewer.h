#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"

class SCViewport;
class IDetailsView;

class TORE_API CAssetViewer : public FAssetEditorToolkit
{
public:
	static void OpenWindow(UObject* Property);
	static void Shutdown();

private:
	static TSharedPtr<CAssetViewer> Instance;

private:
	void OpenWindow_Internal(UObject* Property);

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	TSharedRef<SDockTab> SpawnViewportTab(const FSpawnTabArgs& InArgs);
	TSharedRef<SDockTab> SpawnPreviewSceneSettingsTab(const FSpawnTabArgs& InArgs);
	TSharedRef<SDockTab> SpawnDetailsViewTab(const FSpawnTabArgs& InArgs);

public:
	//Inherited from FAssetEditorToolkit
	virtual FName GetToolkitFName() const override;				
	virtual FText GetBaseToolkitName() const override;			
	virtual FString GetWorldCentricTabPrefix() const override;	
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

private:
	TSharedPtr<SCViewport> Viewport;
	TSharedPtr<SWidget> PreviewSceneSettings;
	TSharedPtr<IDetailsView> DetailsView;
};
