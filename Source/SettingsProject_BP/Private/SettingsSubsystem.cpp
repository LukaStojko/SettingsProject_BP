// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsSubsystem.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "SettingsGameInstance.h"

void USettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    LoadSettings(); // Load settings first

    UE_LOG(LogTemp, Warning, TEXT("Subsystem Initialize called"));

	Audio = NewObject<UAudioSettingsCustom>(this);
    if (Audio && Settings)
    {
        Audio->Initialize(Settings);
    }

	Gameplay = NewObject<UGameplaySettingsCustom>(this);
    if (Gameplay && Settings)
    {
        Gameplay->Initialize(Settings);
    }
    
	Localization = NewObject<ULocalizationSettingsCustom>(this);
    if(Localization && Settings)
    {
        Localization->Initialize(Settings);
	}
}

void USettingsSubsystem::LoadSettings()
{
    if (UGameplayStatics::DoesSaveGameExist(SaveSlot, 0))
    {
        Settings = Cast<UPlayerSettingsSave>(
            UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));
    }

    if (!Settings)
    {
        Settings = Cast<UPlayerSettingsSave>(
            UGameplayStatics::CreateSaveGameObject(
                UPlayerSettingsSave::StaticClass()));
    }
}

void USettingsSubsystem::SaveSettings()
{
    if (Settings)
    {
        UGameplayStatics::SaveGameToSlot(Settings, SaveSlot, 0);
    }
}

//AUDIO

//GAMEPLAY

//LOCALIZATION