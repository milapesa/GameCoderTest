// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/FFootballTeamData.h"
#include "Data/FootballDataTable.h"
#include "Interfaces/GameModeInterface.h"
#include "GameFramework/GameModeBase.h"
#include "GameCoderTestMilaGameModeBase.generated.h"

UCLASS()
class GAMECODERTESTMILA_API AGameCoderTestMilaGameModeBase : public AGameModeBase, public IGameModeInterface
{
	GENERATED_BODY()

public:

	void BeginPlay() override;
	virtual void SimulateMatchesInterface_Implementation() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Football")
	TSoftObjectPtr<UDataTable> FootballDataTableRef;
	
private:
	
	UPROPERTY()
	UDataTable* FootballDataTable;
	
};
