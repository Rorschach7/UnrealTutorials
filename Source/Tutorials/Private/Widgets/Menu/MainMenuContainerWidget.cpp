// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/MainMenuContainerWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/Menu/GenericDialogWidget.h"
#include "Widgets/Menu/MainMenuWidget.h"
#include "Widgets/Menu/SettingsWidget.h"

void UMainMenuContainerWidget::NativeOnInitialized() {
    Super::NativeOnInitialized();

    // Set input mode to ui only, since we are in an ui only main menu
    GetOwningPlayer()->SetInputMode(FInputModeUIOnly());
    GetOwningPlayer()->bShowMouseCursor = true;

    // Set focus to the viewport, so we do not need to click inside the viewport first for the controls to work
    UWidgetBlueprintLibrary::SetFocusToGameViewport();

    // We can only add widgets to the stack after it is initialized. So we delay adding the actual main menu until the first tick. 
    GetWorld()->GetTimerManager().SetTimerForNextTick([this] {
        // Bind main menu buttons
        UMainMenuWidget* MainMenuWidget = Cast<UMainMenuWidget>(MainStack->AddWidget(MainMenuClass));    
        MainMenuWidget->GetSettingsButton()->OnClicked().AddUObject(this, &UMainMenuContainerWidget::OpenSettings);
        MainMenuWidget->GetQuitButton()->OnClicked().AddUObject(this, &UMainMenuContainerWidget::OpenQuitDialog);
        
    });
}

void UMainMenuContainerWidget::OpenSettings() {
    MainStack->AddWidget(SettingsClass);
}

void UMainMenuContainerWidget::OpenQuitDialog() {
    UGenericDialogWidget* DialogWidget = DialogStack->AddWidget<UGenericDialogWidget>(DialogWidgetClass);
    DialogWidget->InitDialog(NSLOCTEXT("MainMenu", "QuitHeader", "Quit Game?"), NSLOCTEXT("MainMenu", "QuitBody", "Dou you really want to quit the game?"),
        NSLOCTEXT("MainMenu", "Quit", "Quit"), NSLOCTEXT("MainMenu", "No", "No"));

    // Bind to confirm event to actually quit the game using a lambda expression
    DialogWidget->OnConfirm().AddLambda([this]() {
        UE_LOG(LogTemp, Warning, TEXT("Closing App"));
        UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
    });
}
