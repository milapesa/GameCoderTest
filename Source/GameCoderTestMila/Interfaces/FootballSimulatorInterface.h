#pragma once

#include "CoreMinimal.h"
#include "GameCoderTestMila/Data/FFootballTeamData.h"
#include "UObject/Interface.h"
#include "FootballSimulatorInterface.generated.h"

UINTERFACE(MinimalAPI, NotBlueprintable)
class UFootballSimulatorInterface : public UInterface
{
	GENERATED_BODY()
};

class GAMECODERTESTMILA_API IFootballSimulatorInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Football")
	virtual void SimulateMatches() = 0;

	//Sorting teams by best to worst function
	UFUNCTION(BlueprintCallable, Category = "Football")
	virtual TArray<FFootballTeamData> GetSortedFootballTeams() const = 0;
};
