// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectWidget.generated.h"

class AMyPaperCharacter_ZD;
class BindWidget;

/**
 * 
 */
UCLASS()
class PAPER2D_UE5_API UCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
    TSubclassOf<AMyPaperCharacter_ZD> CharacterClass1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
    TSubclassOf<AMyPaperCharacter_ZD> CharacterClass2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
    TSubclassOf<AMyPaperCharacter_ZD> CharacterClass3;


    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UButton> Button_0;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UButton> Button_1;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UButton> Button_2;


public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "Character")
    void OnCharacter1Selected();

    UFUNCTION(BlueprintCallable, Category = "Character")
    void OnCharacter2Selected();

    UFUNCTION(BlueprintCallable, Category = "Character")
    void OnCharacter3Selected();
	
};
