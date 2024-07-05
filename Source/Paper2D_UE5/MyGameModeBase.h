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

	//선택한 케릭터를 Spawn시키기
	UFUNCTION(BlueprintCallable, Category = "Character")
	void SpawnSelectedCharacter();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	AActor* SpawnPoint;


	//아직 사용하지 않음.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Controllers", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<ACharacter>, TSubclassOf<APlayerController>> CharacterControllerMap;
	
private:
	TSubclassOf<ACharacter> SelectedCharacterClass;

	//스폰한 케릭터에 대한 케릭터 컨트롤러 선택하기
	void SetPlayerControllerForCharacter();	

	void InitializeCharacterControllerMap();

	void RemoveDefaultPawn();
	
};
