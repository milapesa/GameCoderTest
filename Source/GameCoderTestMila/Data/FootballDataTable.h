#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FFootballTeamData.h"
#include "Engine/DataTable.h"
#include "FootballDataTable.generated.h"

UCLASS()
class GAMECODERTESTMILA_API UFootballDataTable : public UDataTable
{
public:
	GENERATED_BODY()

	//Sorting teams by best to worst function
	UFUNCTION(BlueprintPure, Category = "Football Data")
	TArray<FName> SortFootballTeams();

	// Function to delete all data in the DataTable
	UFUNCTION(BlueprintCallable, Category = "Football Data")
	void ClearTableRows();
};
