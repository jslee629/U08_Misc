#include "CSlicableMesh.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

ACSlicableMesh::ACSlicableMesh()
{
	DefaultRootComp = CreateDefaultSubobject<USceneComponent>("DefaultRootComp");
	RootComponent = DefaultRootComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(DefaultRootComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube"));
	if (StaticMeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(StaticMeshAsset.Object);
	}

	StaticMeshComp->SetVisibility(false);
	StaticMeshComp->SetCollisionProfileName("NoCollision");

	ProcMeshComp = CreateDefaultSubobject<UProceduralMeshComponent>("ProcMeshComp");
	ProcMeshComp->SetupAttachment(DefaultRootComp);

	ProcMeshComp->SetSimulatePhysics(true);
	ProcMeshComp->bUseComplexAsSimpleCollision = false;

	bRunConstructionScriptOnDrag = false;
}

void ACSlicableMesh::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(StaticMeshComp, 0, ProcMeshComp, true);
}
