// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectWidget.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"


void UCharacterSelectWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (Button_0)
    {
        Button_0->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter1Selected);
    }

    if (Button_1)
    {
        Button_1->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter2Selected);
    }

    if (Button_2)
    {
        Button_2->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter3Selected);
    }
}


void UCharacterSelectWidget::OnCharacter1Selected()
{
    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
    if (GameMode)
    {
        GameMode->SetPlayerCharacter(CharacterClass1);        
        HideCharacterSelectWidget();
        UE_LOG(LogTemp, Warning, TEXT("CharacterClass1 가 선택되었습니다."));
    }
}

void UCharacterSelectWidget::OnCharacter2Selected()
{
    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
    if (GameMode)
    {
        GameMode->SetPlayerCharacter(CharacterClass2);        
        HideCharacterSelectWidget();

        UE_LOG(LogTemp, Warning, TEXT("CharacterClass2 가 선택되었습니다."));
    }
}

void UCharacterSelectWidget::OnCharacter3Selected()
{
    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
    if (GameMode)
    {        
        GameMode->SetPlayerCharacter(CharacterClass3);        
        HideCharacterSelectWidget();

        UE_LOG(LogTemp, Warning, TEXT("CharacterClass3 가 선택되었습니다."));
    }
}

void UCharacterSelectWidget::HideCharacterSelectWidget()
{
    //Show/HIde    
    SetVisibility(ESlateVisibility::Hidden);
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = false;
        PlayerController->SetInputMode(FInputModeGameOnly());
    }
}