#include "SCViewport.h"
#include "CViewportClient.h"
#include "AdvancedPreviewScene.h"

SCViewport::SCViewport()
{
    Scene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));
}

void SCViewport::Construct(const FArguments& InArgs)
{
    SEditorViewport::Construct(InArgs);

    FloorMesh = NewObject<UStaticMeshComponent>(GetTransientPackage(), NAME_None, RF_Transient);
    UStaticMesh* FloorAsset = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/MapTemplates/SM_Template_Map_Floor"));
    FloorMesh->SetStaticMesh(FloorAsset);

    FTransform TM;
    Scene->AddComponent(FloorMesh, TM);

    AssetMesh = NewObject<UStaticMeshComponent>(GetTransientPackage(), NAME_None, RF_Transient);
    UStaticMesh* MikuAsset = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Meshes/SM_Miku"));
    AssetMesh->SetStaticMesh(MikuAsset);

    //TM.SetLocation(FVector(0.f, 0.f, 20.f));
    Scene->AddComponent(AssetMesh, TM);
}

TSharedRef<FEditorViewportClient> SCViewport::MakeEditorViewportClient()
{
    Client = MakeShareable(new CViewportClient(Scene.Get(), SharedThis(this)));
    return Client.ToSharedRef();
}

void SCViewport::AddReferencedObjects(FReferenceCollector& Collector)
{
    Collector.AddReferencedObject(AssetMesh);
    Collector.AddReferencedObject(FloorMesh);
}

TSharedRef<FAdvancedPreviewScene> SCViewport::GetScene()
{
    return Scene.ToSharedRef();
}
