#include "FootballDataTable.h"

TArray<FName> UFootballDataTable::SortFootballTeams()
{
	TArray<FFootballTeamData*> FootballTeamsData;
	TArray<FName> SortedTeamNames;
	GetAllRows("", FootballTeamsData);
	
	FootballTeamsData.Sort([](const FFootballTeamData& Team1, const FFootballTeamData& Team2)
	{
		if (Team1.GamesWon != Team2.GamesWon)
			return Team1.GamesWon > Team2.GamesWon;

		return Team1.GetGoalDifference() > Team2.GetGoalDifference();
	});
	
	for (const FFootballTeamData* TeamData : FootballTeamsData)
	{
		SortedTeamNames.Add(FName(*TeamData->TeamName));
		AddRow(FName(*TeamData->TeamName), *TeamData);
	}
	 return SortedTeamNames;
}

void UFootballDataTable::ClearTableRows()
{
	TArray<FName> RowNames = GetRowNames();
	for (const FName& RowName : RowNames)
	{
		RemoveRow(RowName);
	}
}