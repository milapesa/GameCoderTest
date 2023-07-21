// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameCoderTestMilaGameModeBase.h"

#include "Engine/AssetManager.h"

void AGameCoderTestMilaGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FootballDataTable = FootballDataTableRef.LoadSynchronous();

	// FootballDataTable = Cast<UDataTable>(UAssetManager::GetStreamableManager().LoadSynchronous(FootballDataTableRef.ToSoftObjectPath()));
	if (!FootballDataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load FootballDataTable from the Asset Reference."));
		return;
	}
}

void AGameCoderTestMilaGameModeBase::SimulateMatchesInterface_Implementation()
{
	TArray<FFootballTeamData*> FootballTeamsData;
	FootballDataTable->GetAllRows("", FootballTeamsData);
	const int32 NumTeams = FootballTeamsData.Num();
	
	for (int32 i = 0; i < NumTeams; ++i)
	{
		for (int32 j = i + 1; j < NumTeams; ++j)
		{
			FFootballTeamData& Team1 = *FootballTeamsData[i];
			FFootballTeamData& Team2 = *FootballTeamsData[j];

			if (bool TeamWon = FMath::RandBool())
			{
				Team1.GamesPlayed++;
				Team1.GamesWon++;
				Team1.GoalsFor += 2;
				Team2.GamesPlayed++;
				Team2.GamesLost++;
				Team2.GoalsAgainst += 2;
			}
			else
			{
				Team2.GamesPlayed++;
				Team2.GamesWon++;
				Team2.GoalsFor += 2;
				Team1.GamesPlayed++;
				Team1.GamesLost++;
				Team1.GoalsAgainst += 2;
			}
		}
	}
}
