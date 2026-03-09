// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSettingsSave.generated.h"

/**
 * 
 */
UCLASS()
class SETTINGSPROJECT_BP_API UPlayerSettingsSave : public USaveGame
{
	GENERATED_BODY()

public:

    // AUDIO
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MasterVolume = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MusicVolume = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SFXVolume = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DialogueVolume = 1.0f;

    // GAMEPLAY
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MouseSensitivity = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInvertY = false;

    // UI
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UIScale = 1.0f;

    // ACCESSIBILITY
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSubtitlesEnabled = true;

    // LOCALIZATION
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Language = TEXT("en");
};
