// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "PlayerSettingsSave.h"

#include "GameplaySettingsCustom.generated.h"

/**
 * 
 */
UCLASS()
class SETTINGSPROJECT_BP_API UGameplaySettingsCustom : public UObject
{
	GENERATED_BODY()
	
public:
    void Initialize(UPlayerSettingsSave* InSettings);

    UFUNCTION(BlueprintCallable)
    void SetMouseSensitivity(float Value);
    UFUNCTION(BlueprintCallable)
    float GetMouseSensitivity() const;

private:
    UPROPERTY()
    UPlayerSettingsSave* Settings;
};
