// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "MainMenuContainerWidget.generated.h"

class UGenericDialogWidget;
class UMainMenuWidget;
class USettingsWidget;
class UCommonActivatableWidgetStack;

/**
 * 
 */
UCLASS()
class TUTORIALS_API UMainMenuContainerWidget : public UCommonUserWidget {
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UCommonActivatableWidgetStack* MainStack;
    UPROPERTY(meta = (BindWidget))
    UCommonActivatableWidgetStack* DialogStack;

    UPROPERTY(EditAnywhere, Category = "Container")
    TSubclassOf<UMainMenuWidget> MainMenuClass;    
    UPROPERTY(EditAnywhere, Category = "Container")
    TSubclassOf<USettingsWidget> SettingsClass;
    UPROPERTY(EditAnywhere, Category = "Container")
    TSubclassOf<UGenericDialogWidget> DialogWidgetClass;

    virtual void NativeOnInitialized() override;

    virtual void OpenSettings();
    virtual void OpenQuitDialog();
    
};
