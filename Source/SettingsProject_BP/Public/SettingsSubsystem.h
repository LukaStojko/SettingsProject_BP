// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "PlayerSettingsSave.h"

#include "SettingsSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLanguageChanged);

UCLASS()
class SETTINGSPROJECT_BP_API USettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintCallable)
    void SaveSettings();
    UFUNCTION(BlueprintCallable)
    void LoadSettings();

    // AUDIO
    UFUNCTION(BlueprintCallable)
    void SetMasterVolume(float Value);
    UFUNCTION(BlueprintCallable)
    float GetMasterVolume() const;
    UFUNCTION(BlueprintCallable)
    void SetMusicVolume(float Value);
    UFUNCTION(BlueprintCallable)
    float GetMusicVolume() const;
    UFUNCTION(BlueprintCallable)
    void SetSFXVolume(float Value);
    UFUNCTION(BlueprintCallable)
    float GetSFXVolume() const;
    UFUNCTION(BlueprintCallable)
    void SetDialogueVolume(float Value);
    UFUNCTION(BlueprintCallable)
    float GetDialogueVolume() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundMix* AudioSoundMix;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundClass* MasterClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundClass* MusicClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundClass* SFXClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundClass* DialogueClass;

    // GAMEPLAY
    UFUNCTION(BlueprintCallable)
    void SetMouseSensitivity(float Value);
    UFUNCTION(BlueprintCallable)
    float GetMouseSensitivity() const;

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

    UPROPERTY(BlueprintAssignable)
    FOnLanguageChanged OnLanguageChanged;
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetAvailableLanguages() const;

private:
    UPROPERTY()
    UPlayerSettingsSave* Settings;
    FString SaveSlot = TEXT("PlayerSettings");

    void ApplyAudioSettings();

    // CSV STORAGE
    TMap<FString, FString> LocalizationData;

    // CSV Loader
    bool LoadLocalizationForLanguage(const FString& Language);
};
