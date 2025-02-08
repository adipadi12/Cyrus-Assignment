// ScoreWidget.cpp
#include "UScoreWidget.h"
#include "Components/TextBlock.h"

void UScoreWidget::UpdateScore(int32 NewScore)
{
    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(NewScore));
    }
}