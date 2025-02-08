#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxActor.generated.h"

UCLASS()
class FPSSHOOTER_API ABoxActor : public AActor
{
    GENERATED_BODY()

public:
    ABoxActor();

    virtual void BeginPlay() override;

    /** Box mesh component */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* BoxMesh;

    /** Health points for the box */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Properties")
    int32 Health;

    /** Points awarded when the box is destroyed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Properties")
    int32 Score;

    /**
     * Applies damage to the box.
     * @param DamageAmount The amount of damage (usually 1 per hit).
     */
    void ApplyDamage(int32 DamageAmount);

    /**
     * Updates the box’s color using a dynamic material.
     * @param NewColor The new color.
     */
    void UpdateColor(const FLinearColor& NewColor);

protected:
    /** Dynamic material instance for runtime changes */
    UMaterialInstanceDynamic* DynamicMaterial;
};
