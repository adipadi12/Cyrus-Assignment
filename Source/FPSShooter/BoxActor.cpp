#include "BoxActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"

ABoxActor::ABoxActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create the box mesh and set as the RootComponent.
    BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
    RootComponent = BoxMesh;
}

void ABoxActor::BeginPlay()
{
    Super::BeginPlay();

    // Create a dynamic material instance from the mesh’s material.
    if (BoxMesh)
    {
        DynamicMaterial = BoxMesh->CreateAndSetMaterialInstanceDynamic(0);
    }
}

void ABoxActor::UpdateColor(const FLinearColor& NewColor)
{
    if (DynamicMaterial)
    {
        // Assumes your material has a Vector Parameter named "ColorParam"
        DynamicMaterial->SetVectorParameterValue(TEXT("ColorParam"), NewColor);
    }
}

void ABoxActor::ApplyDamage(int32 DamageAmount)
{
    Health -= DamageAmount;
    if (Health <= 0)
    {
        // (Optional) Award score by calling a function on your GameMode/PlayerState.
        Destroy();
    }
}
