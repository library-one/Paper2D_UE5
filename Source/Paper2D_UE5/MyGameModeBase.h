// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class PAPER2D_UE5_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Character")
	void SetPlayerCharacter(TSubclassOf<ACharacter> NewCharacterClass);

	//������ �ɸ��͸� Spawn��Ű��
	UFUNCTION(BlueprintCallable, Category = "Character")
	void SpawnSelectedCharacter();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	AActor* SpawnPoint;


	//���� ������� ����.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Controllers", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<ACharacter>, TSubclassOf<APlayerController>> CharacterControllerMap;
	
private:
	TSubclassOf<ACharacter> SelectedCharacterClass;

	//������ �ɸ��Ϳ� ���� �ɸ��� ��Ʈ�ѷ� �����ϱ�
	void SetPlayerControllerForCharacter();	

	void InitializeCharacterControllerMap();

	void RemoveDefaultPawn();
	
};
