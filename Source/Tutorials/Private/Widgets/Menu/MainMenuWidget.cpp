// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorials/Public/Widgets/Menu/MainMenuWidget.h"

#include "CommonInputSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/CustomButton.h"

void UMainMenuWidget::NativeOnInitialized() {
    Super::NativeOnInitialized();

    NewGameBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnNewGame);    
    CreditsBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnCredits);
   
}

UWidget* UMainMenuWidget::NativeGetDesiredFocusTarget() const {
    UE_LOG(LogTemp, Warning, TEXT("Get Focus Target"));
    return NewGameBtn;
}

void UMainMenuWidget::OnNewGame() {
    UGameplayStatics::OpenLevelBySoftObjectPtr(this, NewGameLevel);
}

void UMainMenuWidget::OnCredits() {
    // TODO:
}

void UMainMenuWidget::OnInputMethodChanged(ECommonInputType NewInputType) {
    if (NewInputType == ECommonInputType::Gamepad) {
        NewGameBtn->SetFocus();
    }
}

UCommonButtonBase* UMainMenuWidget::GetSettingsButton() const {
    return SettingsBtn;
}

UCommonButtonBase* UMainMenuWidget::GetCreditsButton() const {
    return CreditsBtn;
}

UCommonButtonBase* UMainMenuWidget::GetQuitButton() const {
    return QuitBtn;
}
