// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalizationSettingsCustom.h"

void ULocalizationSettingsCustom::Initialize(
    UPlayerSettingsSave* InSettings
)
{
    Settings = InSettings;
	SetLanguage(Settings->Language);
}

void ULocalizationSettingsCustom::SetLanguage(const FString& CultureCode)
{
    if (!Settings)
        return;

    Settings->Language = CultureCode;

    LoadLocalizationForLanguage(CultureCode);

    //SaveSettings();

    OnLanguageChanged.Broadcast();
}

FString ULocalizationSettingsCustom::GetLanguage() const
{
    return Settings ? Settings->Language : TEXT("en");
}

FString ULocalizationSettingsCustom::GetLocalizedText(const FString& Key) const
{
    const FString* Text = LocalizationData.Find(Key);

    if (!Text)
        return Key;

    return *Text;
}

bool ULocalizationSettingsCustom::LoadLocalizationForLanguage(const FString& Language)
{
    LocalizationData.Empty();

    FString LangPath =
        FPaths::ProjectContentDir() +
        TEXT("Localization/") +
        Language +
        TEXT("/");

    IFileManager& FileManager = IFileManager::Get();

    TArray<FString> CSVFiles;
    FileManager.FindFiles(CSVFiles, *(LangPath + TEXT("*.csv")), true, false);

    if (CSVFiles.Num() == 0)
    {
        UE_LOG(LogTemp, Error,
            TEXT("No CSV files found for language %s"),
            *Language);
        return false;
    }

    for (const FString& File : CSVFiles)
    {
        FString FullPath = LangPath + File;

        FString Content;
        if (!FFileHelper::LoadFileToString(Content, *FullPath))
        {
            UE_LOG(LogTemp, Warning,
                TEXT("Failed to load %s"),
                *FullPath);
            continue;
        }

        TArray<FString> Lines;
        Content.ParseIntoArrayLines(Lines);

        for (int32 i = 1; i < Lines.Num(); i++)
        {
            TArray<FString> Cells;
            Lines[i].ParseIntoArray(Cells, TEXT(","));

            if (Cells.Num() < 2)
                continue;

            LocalizationData.Add(Cells[0], Cells[1]);
        }

        UE_LOG(LogTemp, Warning,
            TEXT("Loaded CSV: %s"),
            *File);
    }

    UE_LOG(LogTemp, Warning,
        TEXT("Localization entries loaded: %d"),
        LocalizationData.Num());

    return true;
}

TArray<FString> ULocalizationSettingsCustom::GetAvailableLanguages() const
{
    TArray<FString> Languages;

    FString BasePath =
        FPaths::ProjectContentDir() +
        TEXT("Localization/");

    IFileManager& FileManager = IFileManager::Get();

    FileManager.FindFiles(Languages, *(BasePath + TEXT("*")), false, true);

    return Languages;
}