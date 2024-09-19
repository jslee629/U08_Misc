#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "CVertexMesh.generated.h"

class UProceduralMeshComponent;

UCLASS()
class MISC_API ACVertexMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	ACVertexMesh();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void AddIndicies(int32 StartIndex);

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UProceduralMeshComponent* ProcMeshComp;

	TArray<FVector> Positions;
	TArray<int32> Indicies;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FColor> Colors;
	TArray<FProcMeshTangent> Tangents;
};
