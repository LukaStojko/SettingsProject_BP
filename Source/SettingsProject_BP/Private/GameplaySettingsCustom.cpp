// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySettingsCustom.h"

void UGameplaySettingsCustom::Initialize(
    UPlayerSettingsSave* InSettings
)
{
	Settings = InSettings;
}

void UGameplaySettingsCustom::SetMouseSensitivity(float Value)
{
    if (!Settings) return;

    Settings->MouseSensitivity = Value;
}
float UGameplaySettingsCustom::GetMouseSensitivity() const
{
    return Settings ? Settings->MouseSensitivity : 1.0f;
}