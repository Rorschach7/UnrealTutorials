// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorials/Public/Widgets/MainMenuWidget.h"

#include "CommonButtonBase.h"

void UMainMenuWidget::NativeOnInitialized() {
	Super::NativeOnInitialized();

	NewGameBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnNewGame);
	SettingsBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnSettings);
	CreditsBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnCredits);
	QuitBtn->OnClicked().AddUObject(this, &UMainMenuWidget::OnQuit);
}

void UMainMenuWidget::OnNewGame() {
	// TODO:
}

void UMainMenuWidget::OnSettings() {
	// TODO:
}

void UMainMenuWidget::OnCredits() {
	// TODO:
}

void UMainMenuWidget::OnQuit() {
	// TODO:
}
