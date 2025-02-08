#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/IHttpRequest.h"
#include "JSONDataManager.generated.h" // Must be last include
#include "BoxActorr.h"

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

// Add to JSONDataManager.h
#include "BoxActor.h"

USTRUCT()
struct FBoxTypeData
{
    GENERATED_BODY()

    UPROPERTY()
    FString Name;

    UPROPERTY()
    FLinearColor Color;

    UPROPERTY()
    int32 Health;

    UPROPERTY()
    int32 Score;
};

USTRUCT()
struct FBoxObjectData
{
    GENERATED_BODY()

    UPROPERTY()
    FString Type;

    UPROPERTY()
    FTransform Transform;
};

// In JSONDataManager.cpp
void UJSONDataManager::OnResponseReceived(...)
{
    // ... previous error checking

    TArray<TSharedPtr<FJsonValue>> TypesArray = JsonObject->GetArrayField("types");
    TMap<FString, FBoxTypeData> TypeMap;

    // Parse types
    for (auto& TypeValue : TypesArray)
    {
        TSharedPtr<FJsonObject> TypeObj = TypeValue->AsObject();
        FBoxTypeData TypeData;

        TypeData.Name = TypeObj->GetStringField("name");

        TArray<TSharedPtr<FJsonValue>> ColorArray = TypeObj->GetArrayField("color");
        TypeData.Color = FLinearColor(
            ColorArray[0]->AsNumber(),
            ColorArray[1]->AsNumber(),
            ColorArray[2]->AsNumber()
        );

        TypeData.Health = TypeObj->GetIntegerField("health");
        TypeData.Score = TypeObj->GetIntegerField("score");

        TypeMap.Add(TypeData.Name, TypeData);
    }

    // Parse objects
    TArray<TSharedPtr<FJsonValue>> ObjectsArray = JsonObject->GetArrayField("objects");
    for (auto& ObjValue : ObjectsArray)
    {
        TSharedPtr<FJsonObject> Obj = ObjValue->AsObject();
        FBoxObjectData ObjectData;

        ObjectData.Type = Obj->GetStringField("type");

        TSharedPtr<FJsonObject> TransformObj = Obj->GetObjectField("transform");
        // Parse transform components and set ObjectData.Transform
        // ... (implementation omitted for brevity)

        // Spawn actor
        if (TypeMap.Contains(ObjectData.Type))
        {
            FBoxTypeData Type = TypeMap[ObjectData.Type];
            FActorSpawnParameters Params;
            ABoxActor* NewBox = GetWorld()->SpawnActor<ABoxActor>(ABoxActor::StaticClass(), ObjectData.Transform, Params);

            NewBox->Health = Type.Health;
            NewBox->ScoreValue = Type.Score;
            NewBox->DynamicMaterial->SetVectorParameterValue("Color", Type.Color);
        }
    }
}