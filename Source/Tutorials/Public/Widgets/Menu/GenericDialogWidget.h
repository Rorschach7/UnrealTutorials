// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GenericDialogWidget.generated.h"

class UCustomButton;
class UCommonTextBlock;

DECLARE_EVENT(UGenericDialogWidget, FGenericDialogEvent);

/**
 * 
 */
UCLASS()
class TUTORIALS_API UGenericDialogWidget : public UCommonActivatableWidget {
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UCommonTextBlock* HeaderTextBlock;
    UPROPERTY(meta = (BindWidget))
    UCommonTextBlock* BodyTextBlock;
    UPROPERTY(meta = (BindWidget))
    UCustomButton* ConfirmButton;
    UPROPERTY(meta = (BindWidget))
    UCustomButton* CancelButton;

    FGenericDialogEvent ConfirmEvent;
    FGenericDialogEvent CancelEvent;

    virtual UWidget* NativeGetDesiredFocusTarget() const override;

    virtual void Confirm();
    virtual void Cancel();

public:
    
    FGenericDialogEvent& OnConfirm() { return ConfirmEvent; }
    FGenericDialogEvent& OnCancel() { return CancelEvent; }
    
    virtual void InitDialog(const FText& HeaderText, const FText& BodyText, const  FText& ConfirmText, const FText& CancelText);
    
};
