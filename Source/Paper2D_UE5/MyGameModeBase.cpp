// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	// ��������� Ŭ������ ����Ʈ Pawn Ŭ������ �����ϴ� ���
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Paper2D/BP_Character"));	
		
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

		
	static ConstructorHelpers::FClassFinder<APlayerController> ControllClass(TEXT("/Game/Paper2D/BP_MyPlayerController"));

	if (ControllClass.Class != NULL)
	{
		PlayerControllerClass = ControllClass.Class;
	}

	//�Ϲ� C++ Ŭ������  �����ϴ� ���
	//DefaultPawnClass = AMyPaperCharacter::StaticClass();
	//PlayerControllerClass = AMyPlayerController::StaticClass();
}