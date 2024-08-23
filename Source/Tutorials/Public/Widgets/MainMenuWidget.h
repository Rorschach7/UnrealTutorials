// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "MainMenuWidget.generated.h"

class UCommonButtonBase;

UCLASS()
class TUTORIALS_API UMainMenuWidget : public UCommonUserWidget {
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UCommonButtonBase* NewGameBtn;
    UPROPERTY(meta = (BindWidget))
    UCommonButtonBase* SettingsBtn;
    UPROPERTY(meta = (BindWidget))
    UCommonButtonBase* CreditsBtn;
    UPROPERTY(meta = (BindWidget))
    UCommonButtonBase* QuitBtn;

    virtual void NativeOnInitialized() override;

    virtual void OnNewGame();
    virtual void OnSettings();
    virtual void OnCredits();
    virtual void OnQuit();    
};
