// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "AudioSettingsCustom.h"
#include "LocalizationSettingsCustom.h"

#include "PlayerSettingsSave.h"

#include "SettingsSubsystem.generated.h"

/**
 * 
 */

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
    UAudioSettingsCustom* GetAudioSettings() const { return Audio; }

    // GAMEPLAY
    UFUNCTION(BlueprintCallable)
    void SetMouseSensitivity(float Value);
    UFUNCTION(BlueprintCallable)
    float GetMouseSensitivity() const;

    //LOCALIZATION
    UFUNCTION(BlueprintCallable)
	ULocalizationSettingsCustom* GetLocalizationSettings() const { return Localization; }

private:
    UPROPERTY()
    UPlayerSettingsSave* Settings;
    FString SaveSlot = TEXT("PlayerSettings");

    UAudioSettingsCustom* Audio;
	ULocalizationSettingsCustom* Localization;
};
