// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_HUD.h"

FPS_HUD::FPS_HUD()
{
}

FPS_HUD::~FPS_HUD()
{
}

void AFPS_HUD::DrawHUD()
{
    Super::DrawHUD();

    // Draw score text at screen position (50,50)
    FVector2D ScreenLocation(50.f, 50.f);
    FString ScoreText = FString::Printf(TEXT("Score: %d"), PlayerScore);
    DrawText(ScoreText, FLinearColor::White, ScreenLocation.X, ScreenLocation.Y);
}
