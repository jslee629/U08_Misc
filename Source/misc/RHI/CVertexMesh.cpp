#include "CVertexMesh.h"

ACVertexMesh::ACVertexMesh()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;

	ProcMeshComp = CreateDefaultSubobject<UProceduralMeshComponent>("ProcMesh");
	RootComponent = ProcMeshComp;

	FVector V = FVector(0.5f);

	//Front
	Positions.Add(FVector(-V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(0.f, 1.f));
	Positions.Add(FVector(-V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(0.f, 0.f));
	Positions.Add(FVector(-V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(1.f, 1.f));
	Positions.Add(FVector(-V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(1.f, 0.f));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(-1.f, 0.f, 0.f));
		Tangents.Add(FProcMeshTangent(0.f, 1.f, 0.f));
		Colors.Add(FColor::Red);
	}
	AddIndicies(0);

	//Back
	Positions.Add(FVector(+V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(0, 1));
	Positions.Add(FVector(+V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(0, 0));
	Positions.Add(FVector(+V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(1, 1));
	Positions.Add(FVector(+V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(1, 0));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(+1, 0, 0));
		Tangents.Add(FProcMeshTangent(0.f, -1.f, 0.f));
		Colors.Add(FColor::Green);
	}
	AddIndicies(4);


	//Top
	Positions.Add(FVector(-V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(0, 1));
	Positions.Add(FVector(+V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(0, 0));
	Positions.Add(FVector(-V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(1, 1));
	Positions.Add(FVector(+V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(1, 0));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(0.f, 0.f, +1.f));
		Tangents.Add(FProcMeshTangent(0.f, 1.f, 0.f));
		Colors.Add(FColor::Blue);
	}
	AddIndicies(8);


	//Bottom
	Positions.Add(FVector(-V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(0, 1));
	Positions.Add(FVector(-V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(1, 1));
	Positions.Add(FVector(+V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(0, 0));
	Positions.Add(FVector(+V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(1, 0));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(0.f, 0.f, -1.f));
		Tangents.Add(FProcMeshTangent(0.f, 1.f, 0.f));
		Colors.Add(FColor::Cyan);
	}
	AddIndicies(12);


	//Left
	Positions.Add(FVector(+V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(0, 1));
	Positions.Add(FVector(+V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(0, 0));
	Positions.Add(FVector(-V.X, -V.Y, -V.Z)); UVs.Add(FVector2D(1, 1));
	Positions.Add(FVector(-V.X, -V.Y, +V.Z)); UVs.Add(FVector2D(1, 0));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(0.f, -1.f, 0.f));
		Tangents.Add(FProcMeshTangent(1.f, 0.f, 0.f));
		Colors.Add(FColor::Magenta);
	}
	AddIndicies(16);


	//Right
	Positions.Add(FVector(-V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(0, 1));
	Positions.Add(FVector(-V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(0, 0));
	Positions.Add(FVector(+V.X, +V.Y, -V.Z)); UVs.Add(FVector2D(1, 1));
	Positions.Add(FVector(+V.X, +V.Y, +V.Z)); UVs.Add(FVector2D(1, 0));

	for (int32 i = 0; i < 4; i++)
	{
		Normals.Add(FVector(0.f, +1.f, 0.f));
		Tangents.Add(FProcMeshTangent(-1.f, 0.f, 0.f));
		Colors.Add(FColor::Yellow);
	}
	AddIndicies(20);

	ProcMeshComp->CreateMeshSection(0, Positions, Indicies, Normals, UVs, Colors, Tangents, true);
	ProcMeshComp->SetRelativeScale3D(FVector(100.f));

}

void ACVertexMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACVertexMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CPU에서 위치 정보를 바꾸는건 미친짓
	//for (int32 i = 0; i < Positions.Num(); i++)
	//{
	//	Positions[i] += FVector(10.f * DeltaTime, 0.f, 0.f);
	//	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::White, FString::SanitizeFloat(Positions[i].X));
	//}

	for (int32 i = 0; i < Colors.Num(); i += 4)
	{
		FColor RandomColor = FColor::MakeRandomColor();
		RandomColor.A = 255.f;

		Colors[i] = RandomColor;
		Colors[i+1] = RandomColor;
		Colors[i+2] = RandomColor;
		Colors[i+3] = RandomColor;
	}

	ProcMeshComp->UpdateMeshSection(0, Positions, Normals, UVs, Colors, Tangents);
}

void ACVertexMesh::AddIndicies(int32 StartIndex)
{
	Indicies.Add(2 + StartIndex);
	Indicies.Add(1 + StartIndex);
	Indicies.Add(0 + StartIndex);
	Indicies.Add(3 + StartIndex);
	Indicies.Add(1 + StartIndex);
	Indicies.Add(2 + StartIndex);
}