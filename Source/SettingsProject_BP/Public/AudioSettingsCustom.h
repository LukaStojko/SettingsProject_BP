// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "PlayerSettingsSave.h"

#include "AudioSettingsCustom.generated.h"

/**
 * 
 */
 // Forward declarations

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMasterChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMusicChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSFXChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogueChanged);

UCLASS()
class SETTINGSPROJECT_BP_API UAudioSettingsCustom : public UObject
{
	GENERATED_BODY()

public:
    void Initialize(UPlayerSettingsSave* InSettings);

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

    UFUNCTION(BlueprintCallable)
    void ApplyAudioSettings();

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

    UPROPERTY(BlueprintAssignable)
    FOnMasterChanged OnMasterChanged;
    UPROPERTY(BlueprintAssignable)
    FOnMusicChanged OnMusicChanged;
    UPROPERTY(BlueprintAssignable)
    FOnSFXChanged OnSFXChanged;
    UPROPERTY(BlueprintAssignable)
    FOnDialogueChanged OnDialogueChanged;

private:
    UPROPERTY()
    UPlayerSettingsSave* Settings;
};
