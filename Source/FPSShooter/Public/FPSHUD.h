// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class FPSSHOOTER_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
public:
    // Current player score
    UPROPERTY(BlueprintReadWrite, Category = "Score")
    int32 PlayerScore = 0;

protected:
    // Override DrawHUD to render custom UI
    virtual void DrawHUD() override;
};
