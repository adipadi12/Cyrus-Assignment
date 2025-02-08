#include "JSONDataManager.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

UJSONDataManager::UJSONDataManager()
{
    // UE-safe constructor
}

void UJSONDataManager::BeginDestroy()
{
    // Cleanup if needed
    Super::BeginDestroy();
}

void UJSONDataManager::LoadJSONData()
{
    FHttpModule& Http = FHttpModule::Get();
    TSharedRef<IHttpRequest> Request = Http.CreateRequest();

    Request->SetURL("https://raw.githubusercontent.com/CyrusCHAU/Varadise-Technical-Test/refs/heads/main/data.json");
    Request->SetVerb("GET");
    Request->OnProcessRequestComplete().BindUObject(this, &UJSONDataManager::OnResponseReceived);
    Request->ProcessRequest();
}

void UJSONDataManager::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (!bWasSuccessful || Response->GetResponseCode() != 200)
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP request failed! Code: %d"), Response->GetResponseCode());
        return;
    }

    const FString ResponseContent = Response->GetContentAsString();
    UE_LOG(LogTemp, Log, TEXT("JSON Response: %s"), *ResponseContent);

    // Add JSON parsing logic here
}