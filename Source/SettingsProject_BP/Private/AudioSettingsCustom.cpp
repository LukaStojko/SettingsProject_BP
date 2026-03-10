// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioSettingsCustom.h"
#include "Kismet/GameplayStatics.h"
#include "SettingsGameInstance.h"

void UAudioSettingsCustom::Initialize(
    UPlayerSettingsSave* InSettings
)
{
    Settings = InSettings;

    if (UWorld* World = GetWorld())
    {
        if (UGameInstance* GI = World->GetGameInstance())
        {
            UE_LOG(LogTemp, Warning, TEXT("GameInstance found"));

            USettingsGameInstance* MyGI = Cast<USettingsGameInstance>(GI);

            if (MyGI)
            {
                UE_LOG(LogTemp, Warning, TEXT("GameInstance cast SUCCESS"));

                AudioSoundMix = MyGI->AudioSoundMix;
                MasterClass = MyGI->MasterClass;
                MusicClass = MyGI->MusicClass;
                SFXClass = MyGI->SFXClass;
                DialogueClass = MyGI->DialogueClass;
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("GameInstance cast FAILED"));
            }
        }
    }
    ApplyAudioSettings();
}

void UAudioSettingsCustom::SetMasterVolume(float Value)
{
    const float Step = 0.05f;

    Value = FMath::Clamp(Value, 0.0f, 1.0f);
    Value = FMath::RoundToFloat(Value / Step) * Step;

    if (!Settings) return;
    Settings->MasterVolume = Value;

    // Apply immediately to audio system later
    ApplyAudioSettings();
    //SaveSettings();
}
float UAudioSettingsCustom::GetMasterVolume() const
{
    return Settings ? Settings->MasterVolume : 1.0f;
}

void UAudioSettingsCustom::SetMusicVolume(float Value)
{
    const float Step = 0.05f;

    Value = FMath::Clamp(Value, 0.0f, 1.0f);
    Value = FMath::RoundToFloat(Value / Step) * Step;

    if (!Settings) return;
    Settings->MusicVolume = Value;

    // Apply immediately to audio system later
    ApplyAudioSettings();
    //SaveSettings();
}
float UAudioSettingsCustom::GetMusicVolume() const
{
    return Settings ? Settings->MusicVolume : 1.0f;
}

void UAudioSettingsCustom::SetSFXVolume(float Value)
{
    const float Step = 0.05f;

    Value = FMath::Clamp(Value, 0.0f, 1.0f);
    Value = FMath::RoundToFloat(Value / Step) * Step;

    if (!Settings) return;
    Settings->SFXVolume = Value;

    // Apply immediately to audio system later
    ApplyAudioSettings();
    //SaveSettings();
}
float UAudioSettingsCustom::GetSFXVolume() const
{
    return Settings ? Settings->SFXVolume : 1.0f;
}

void UAudioSettingsCustom::SetDialogueVolume(float Value)
{
    const float Step = 0.05f;

    Value = FMath::Clamp(Value, 0.0f, 1.0f);
    Value = FMath::RoundToFloat(Value / Step) * Step;

    if (!Settings) return;
    Settings->DialogueVolume = Value;

    // Apply immediately to audio system later
    ApplyAudioSettings();
    //SaveSettings();
}
float UAudioSettingsCustom::GetDialogueVolume() const
{
    return Settings ? Settings->DialogueVolume : 1.0f;
}

void UAudioSettingsCustom::ApplyAudioSettings()
{
    UE_LOG(LogTemp, Warning, TEXT("ApplyAudioSettings CALLED"));

    if (!Settings)
    {
        UE_LOG(LogTemp, Error, TEXT("Settings is NULL"));
        return;
    }

    if (!AudioSoundMix)
    {
        UE_LOG(LogTemp, Error, TEXT("AudioSoundMix is NULL"));
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL"));
        return;
    }

    UGameplayStatics::PushSoundMixModifier(World, AudioSoundMix);

    // MASTER
    if (MasterClass)
    {
        UGameplayStatics::SetSoundMixClassOverride(
            World,
            AudioSoundMix,
            MasterClass,
            Settings->MasterVolume,
            1.0f,
            0.1f,
            true
        );
    }

    // MUSIC
    if (MusicClass)
    {
        UGameplayStatics::SetSoundMixClassOverride(
            World,
            AudioSoundMix,
            MusicClass,
            Settings->MusicVolume,
            1.0f,
            0.1f,
            true
        );
    }

    // SFX
    if (SFXClass)
    {
        UGameplayStatics::SetSoundMixClassOverride(
            World,
            AudioSoundMix,
            SFXClass,
            Settings->SFXVolume,
            1.0f,
            0.1f,
            true
        );
    }

    // DIALOGUE
    if (DialogueClass)
    {
        UGameplayStatics::SetSoundMixClassOverride(
            World,
            AudioSoundMix,
            DialogueClass,
            Settings->DialogueVolume,
            1.0f,
            0.1f,
            true
        );
    }

    UE_LOG(LogTemp, Warning, TEXT("=== Applying Audio Settings ==="));
    UE_LOG(LogTemp, Warning, TEXT("Master Volume: %f"), Settings->MasterVolume);
    UE_LOG(LogTemp, Warning, TEXT("Music Volume: %f"), Settings->MusicVolume);
    UE_LOG(LogTemp, Warning, TEXT("SFX Volume: %f"), Settings->SFXVolume);
    UE_LOG(LogTemp, Warning, TEXT("Dialogue Volume: %f"), Settings->DialogueVolume);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
            FString::Printf(TEXT("Master: %.2f  Music: %.2f  SFX: %.2f  Dialogue: %.2f"),
                Settings->MasterVolume,
                Settings->MusicVolume,
                Settings->SFXVolume,
                Settings->DialogueVolume));
    }
}