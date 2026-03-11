// Fill out your copyright notice in the Description page of Project Settings.


#include "AccessabilitySettingsCustom.h"

void UAccessabilitySettingsCustom::Initialize(UPlayerSettingsSave* InSettings)
{
	Settings = InSettings;
}

void UAccessabilitySettingsCustom::SetUIScale(float Value)
{
	if (!Settings) return;
	Settings->UIScale = Value;
}
float UAccessabilitySettingsCustom::GetUIScale() const
{
	return Settings ? Settings->UIScale : 1.0f;
}

void UAccessabilitySettingsCustom::SetSubtitlesEnabled(bool bEnabled)
{
	if (!Settings) return;
	Settings->bSubtitlesEnabled = bEnabled;
}
bool UAccessabilitySettingsCustom::GetSubtitlesEnabled() const
{
	return Settings ? Settings->bSubtitlesEnabled : true;
}