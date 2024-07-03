// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter_ZD.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "CharacterSelectWidget.h"


AMyGameModeBase::AMyGameModeBase()
{
	// ��������� Ŭ������ ����Ʈ Pawn Ŭ������ �����ϴ� ���
		
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Paper2D/BP_Character"));	
		
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

		
	static ConstructorHelpers::FClassFinder<APlayerController> ControllClass(TEXT("/Game/Paper2D/BP_MyPlayerController"));

	if (ControllClass.Class != nullptr)
	{
		PlayerControllerClass = ControllClass.Class;
	}

	//�Ϲ� C++ Ŭ������  �����ϴ� ���
	//DefaultPawnClass = AMyPaperCharacter::StaticClass();
	//PlayerControllerClass = AMyPlayerController::StaticClass();
}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// �ʱ� ĳ���� ���� ����
	if (SelectedCharacterClass)
	{

		//DefaultPawnClass = SelectedCharacterClass;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(GetWorld()->SpawnActor<AMyPaperCharacter_ZD>(SelectedCharacterClass));
	}

}

void AMyGameModeBase::SetPlayerCharacter(TSubclassOf<AMyPaperCharacter_ZD> NewCharacterClass)
{
	SelectedCharacterClass = NewCharacterClass;
}