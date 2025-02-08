// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxActorr.generated.h"

UCLASS()
class FPSSHOOTER_API ABoxActorr : public AActor
{
	GENERATED_BODY()
	
public:
    ABoxActorr();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BoxMesh;

    UPROPERTY(EditAnywhere)
    int32 Health;

    UPROPERTY(EditAnywhere)
    int32 ScoreValue;

    UPROPERTY()
    UMaterialInstanceDynamic* DynamicMaterial;

public:
    void TakeDamage(int32 DamageAmount);
};