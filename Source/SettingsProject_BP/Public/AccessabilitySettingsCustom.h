// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "PlayerSettingsSave.h"

#include "AccessabilitySettingsCustom.generated.h"

/**
 * 
 */
UCLASS()
class SETTINGSPROJECT_BP_API UAccessabilitySettingsCustom : public UObject
{
	GENERATED_BODY()
public:
	void Initialize(UPlayerSettingsSave* InSettings);

	UFUNCTION(BlueprintCallable)
	void SetUIScale(float Value);
	UFUNCTION(BlueprintCallable)
	float GetUIScale() const;
	UFUNCTION(BlueprintCallable)
	void SetSubtitlesEnabled(bool bEnabled);
	UFUNCTION(BlueprintCallable)
	bool GetSubtitlesEnabled() const;

private:
	UPROPERTY()
	UPlayerSettingsSave* Settings;
};
