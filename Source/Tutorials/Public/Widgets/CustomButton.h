// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CustomButton.generated.h"

class UCommonTextBlock;

/**
 * 
 */
UCLASS()
class TUTORIALS_API UCustomButton : public UCommonButtonBase {
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UCommonTextBlock* ButtonTextBlock;

    UPROPERTY(EditAnywhere, Category = "Button")
    FText ButtonText;

    virtual void NativePreConstruct() override;
    
};
