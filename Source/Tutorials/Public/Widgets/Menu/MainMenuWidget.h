// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonButtonBase.h"

#include "MainMenuWidget.generated.h"

class UCustomButton;

UCLASS()
class TUTORIALS_API UMainMenuWidget : public UCommonActivatableWidget {
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

    UPROPERTY(EditAnywhere, Category = "Main Menu")
    TSoftObjectPtr<UWorld> NewGameLevel;

    virtual void NativeOnInitialized() override;
    virtual UWidget* NativeGetDesiredFocusTarget() const override;

    virtual void OnNewGame();    
    virtual void OnCredits();
    
    virtual void OnInputMethodChanged(ECommonInputType NewInputType);

public:

    virtual UCommonButtonBase* GetSettingsButton() const;
    virtual UCommonButtonBase* GetCreditsButton() const;
    virtual UCommonButtonBase* GetQuitButton() const;
    
};
