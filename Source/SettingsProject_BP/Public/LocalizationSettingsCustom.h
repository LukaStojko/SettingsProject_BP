// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocalizationSettingsCustom.generated.h"

/**
 * 
 */

UCLASS(BlueprintType)
class SETTINGSPROJECT_BP_API ULocalizationSettingsCustom : public UObject
{
	GENERATED_BODY()
	
public:

    void Initialize(const FString& DefaultLanguage);

    //LOCALIZATION
    // Change current language ("en", "fr", etc)
    UFUNCTION(BlueprintCallable)
    void SetLanguage(const FString& CultureCode);

    // Get current language
    UFUNCTION(BlueprintCallable)
    FString GetLanguage() const;

    // Get localized text by key
    UFUNCTION(BlueprintCallable)
    FString GetLocalizedText(const FString& Key) const;

    UFUNCTION(BlueprintCallable)
    TArray<FString> GetAvailableLanguages() const;
    
    bool LoadLocalizationForLanguage(const FString& Language);

private:

    FString CurrentLanguage;

    // CSV STORAGE
    TMap<FString, FString> LocalizationData;
};