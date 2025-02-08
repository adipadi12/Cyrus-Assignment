#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/IHttpRequest.h"
#include "JSONDataManager.generated.h" // Must be last include

UCLASS() // <-- UE Macro required
class FPSSHOOTER_API UJSONDataManager : public UGameInstance // <-- Inherit from UGameInstance
{
    GENERATED_BODY()

public:
    // Constructor now needs UE-compatible syntax
    UJSONDataManager();

    // Replace destructor with UE's BeginDestroy
    virtual void BeginDestroy() override;

    void LoadJSONData();

private:
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};