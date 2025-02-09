// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/SettingsWidget.h"

#include "Widgets/CustomButton.h"

void USettingsWidget::NativeOnInitialized() {
    Super::NativeOnInitialized();

    // The back button calls the inherited DeactivateWidget function to close this widget
    BackBtn->OnClicked().AddUObject(this, &USettingsWidget::DeactivateWidget);
}

UWidget* USettingsWidget::NativeGetDesiredFocusTarget() const {    
    // TODO: return another widget
    return BackBtn; // This is just temporary
}
