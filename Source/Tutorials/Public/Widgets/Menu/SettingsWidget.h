// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SettingsWidget.generated.h"

class UCustomButton;
/**
 * 
 */
UCLASS()
class TUTORIALS_API USettingsWidget : public UCommonActivatableWidget {
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UCustomButton* BackBtn;

    virtual void NativeOnInitialized() override;
    virtual UWidget* NativeGetDesiredFocusTarget() const override;
    
};
