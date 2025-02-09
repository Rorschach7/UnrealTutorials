// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Menu/GenericDialogWidget.h"

#include "CommonTextBlock.h"
#include "Widgets/CustomButton.h"

UWidget* UGenericDialogWidget::NativeGetDesiredFocusTarget() const {
    return CancelButton;    
}

void UGenericDialogWidget::Confirm() {
    DeactivateWidget();
    ConfirmEvent.Broadcast();
}

void UGenericDialogWidget::Cancel() {
    DeactivateWidget();
    CancelEvent.Broadcast();
}

void UGenericDialogWidget::InitDialog(const FText& HeaderText, const FText& BodyText, const FText& ConfirmText, const FText& CancelText) {
    HeaderTextBlock->SetText(HeaderText);
    BodyTextBlock->SetText(BodyText);

    ConfirmButton->SetButtonText(ConfirmText);
    CancelButton->SetButtonText(CancelText);

    ConfirmButton->OnClicked().AddUObject(this, &UGenericDialogWidget::Confirm);
    CancelButton->OnClicked().AddUObject(this, &UGenericDialogWidget::Cancel);
}
