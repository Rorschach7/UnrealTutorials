// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "MainMenuWidget.generated.h"

class UCustomButton;

UCLASS()
class TUTORIALS_API UMainMenuWidget : public UCommonUserWidget {
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UCustomButton* NewGameBtn;
    UPROPERTY(meta = (BindWidget))
    UCustomButton* SettingsBtn;
    UPROPERTY(meta = (BindWidget))
    UCustomButton* CreditsBtn;
    UPROPERTY(meta = (BindWidget))
    UCustomButton* QuitBtn;

    virtual void NativeOnInitialized() override;

    virtual void OnNewGame();
    virtual void OnSettings();
    virtual void OnCredits();
    virtual void OnQuit();    
};
