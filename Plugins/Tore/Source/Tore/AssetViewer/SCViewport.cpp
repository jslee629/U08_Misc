#include "SCViewport.h"
#include "CViewportClient.h"
#include "AdvancedPreviewScene.h"
//TODO: AdvancedPreviewScene 관련 모듈 추가

SCViewport::SCViewport()
{

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
