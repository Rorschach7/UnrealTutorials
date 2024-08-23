// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/CustomButton.h"

#include "CommonTextBlock.h"

void UCustomButton::NativePreConstruct() {
    Super::NativePreConstruct();

    ButtonTextBlock->SetText(ButtonText);
}
