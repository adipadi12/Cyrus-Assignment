// BoxActor.cpp
#include "BoxActorr.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

ABoxActorr::ABoxActorr()
{
    PrimaryActorTick.bCanEverTick = false;

    BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
    RootComponent = BoxMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxMeshAsset(TEXT("/Engine/BasicShapes/Cube"));
    if (BoxMeshAsset.Succeeded()) BoxMesh->SetStaticMesh(BoxMeshAsset.Object);
}

void ABoxActorr::BeginPlay()
{
    Super::BeginPlay();

    // Create dynamic material
    UMaterialInterface* BaseMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Materials/M_BoxMaterial"));
    DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
    BoxMesh->SetMaterial(0, DynamicMaterial);
}

void ABoxActorr::TakeDamage(int32 DamageAmount)
{
    Health -= DamageAmount;
    if (Health <= 0)
    {
        // Award score and destroy
        if (GetWorld()) GetWorld()->DestroyActor(this);
    }
}