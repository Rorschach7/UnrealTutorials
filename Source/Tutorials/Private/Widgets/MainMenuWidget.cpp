// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorials/Public/Widgets/MainMenuWidget.h"

#include "CommonInputSubsystem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/CustomButton.h"

void UMainMenuWidget::NativeOnInitialized() {
    Super::NativeOnInitialized();

    NewGameBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnNewGame);
    SettingsBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnSettings);
    CreditsBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnCredits);
    QuitBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnQuit);

    // Set input mode to ui only, since we are in an ui only main menu
    GetOwningPlayer()->SetInputMode(FInputModeUIOnly());
    GetOwningPlayer()->bShowMouseCursor = true;

    // Set focus to the viewport, so we do not need to click inside the viewport first for the controls to work
    UWidgetBlueprintLibrary::SetFocusToGameViewport();

    // Bind to the input change event
    GetInputSubsystem()->OnInputMethodChangedNative.AddUObject(this, &UMainMenuWidget::OnInputMethodChanged);
}

void UMainMenuWidget::OnNewGame() {
    UGameplayStatics::OpenLevelBySoftObjectPtr(this, NewGameLevel);
}

void UMainMenuWidget::OnSettings() {
    // TODO:
}

void UMainMenuWidget::OnCredits() {
    // TODO:
}

void UMainMenuWidget::OnQuit() {
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}

void UMainMenuWidget::OnInputMethodChanged(ECommonInputType NewInputType) {
    if (NewInputType == ECommonInputType::Gamepad) {
        NewGameBtn->SetFocus();
    }
}
