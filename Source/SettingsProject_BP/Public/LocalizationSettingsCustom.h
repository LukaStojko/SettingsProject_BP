// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "PlayerSettingsSave.h"

#include "LocalizationSettingsCustom.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLanguageChanged);

UCLASS()
class SETTINGSPROJECT_BP_API ULocalizationSettingsCustom : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(UPlayerSettingsSave* InSettings);

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

    // CSV Loader
    bool LoadLocalizationForLanguage(const FString& Language);

    UPROPERTY(BlueprintAssignable)
    FOnLanguageChanged OnLanguageChanged;

private:
    UPROPERTY()
    UPlayerSettingsSave* Settings;

    // CSV STORAGE
    TMap<FString, FString> LocalizationData;
};
