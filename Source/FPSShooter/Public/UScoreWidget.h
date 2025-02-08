// ScoreWidget.h
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UScoreWidget.generated.h"

UCLASS()
class FPSHOOTER_API UScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void UpdateScore(int32 NewScore);

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;
};