#include "GameCoderTestMilaGameModeBase.h"

void AGameCoderTestMilaGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (!ensure(FootballDataTableRef.LoadSynchronous()))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load FootballDataTable from the Asset Reference."));
	}
}

void UpdateTeamData(FFootballTeamData& Team, int32 GoalsFor, int32 GoalsAgainst)
{
	Team.GamesPlayed++;
	Team.GoalsFor += GoalsFor;
	Team.GoalsAgainst += GoalsAgainst;

	if (GoalsFor > GoalsAgainst)
	{
		Team.GamesWon++;
	}
	else if (GoalsAgainst > GoalsFor)
	{
		Team.GamesLost++;
	}
}

void AGameCoderTestMilaGameModeBase::SimulateMatches()
{
	
	TArray<FFootballTeamData*> FootballTeamsData;
	FootballDataTableRef->GetAllRows("", FootballTeamsData);
	const int32 NumTeams = FootballTeamsData.Num();

	for (const auto TeamsData : FootballTeamsData)
	{
		TeamsData->GamesLost = 0;
		TeamsData->GamesPlayed = 0;
		TeamsData->GamesWon = 0;
		TeamsData->GoalsAgainst = 0;
		TeamsData->GoalsFor = 0;
	}
	for (int32 i = 0; i < NumTeams; ++i)
	{
		for (int32 j = i + 1; j < NumTeams; ++j)
		{
			FFootballTeamData& Team1 = *FootballTeamsData[i];
			FFootballTeamData& Team2 = *FootballTeamsData[j];

			const int32 GoalsTeam1 = FMath::RandRange(0, 3);
			const int32 GoalsTeam2 = FMath::RandRange(0, 3);
			
			UpdateTeamData(Team1, GoalsTeam1, GoalsTeam2); 
			UpdateTeamData(Team2, GoalsTeam2, GoalsTeam1); 
		}
	}
}

TArray<FFootballTeamData> AGameCoderTestMilaGameModeBase::GetSortedFootballTeams() const
{
	TArray<FFootballTeamData*> FootballTeamsData;
	FootballDataTableRef->GetAllRows("", FootballTeamsData);
	
	FootballTeamsData.Sort([](const FFootballTeamData& Team1, const FFootballTeamData& Team2)
	{
		if (Team1.GamesWon != Team2.GamesWon)
			return Team1.GamesWon > Team2.GamesWon;

		if (Team1.GetGoalDifference() != Team2.GetGoalDifference())
			return Team1.GetGoalDifference() > Team2.GetGoalDifference();
		
		return Team1.GamesLost < Team2.GamesLost;
		
	});

	TArray<FFootballTeamData> SortedTeamNames;
	for (const FFootballTeamData* TeamData : FootballTeamsData)
	{
		SortedTeamNames.Add(*TeamData);
	}
	return SortedTeamNames;
}
