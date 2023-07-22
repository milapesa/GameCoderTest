#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FFootballTeamData.generated.h"

USTRUCT(BlueprintType)
struct FFootballTeamData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString TeamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 GamesPlayed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 GamesWon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 GamesLost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 GoalsFor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 GoalsAgainst;

	FFootballTeamData();

	int32 GetGoalDifference() const { return GoalsFor - GoalsAgainst; }
};
