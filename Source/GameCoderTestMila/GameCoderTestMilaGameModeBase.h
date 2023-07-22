#pragma once

#include "CoreMinimal.h"
#include "Data/FFootballTeamData.h"
#include "Interfaces/FootballSimulatorInterface.h"
#include "GameFramework/GameModeBase.h"
#include "GameCoderTestMilaGameModeBase.generated.h"

UCLASS()
class GAMECODERTESTMILA_API AGameCoderTestMilaGameModeBase : public AGameModeBase, public IFootballSimulatorInterface
{
	GENERATED_BODY()

public:

	void BeginPlay() override;

	//Interface connecting the widgets to the Game Mode to simulate the matches between teams.
	virtual void SimulateMatches() override;

	//Sorting teams by best to worst function
	virtual TArray<FFootballTeamData> GetSortedFootballTeams() const override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Football")
	TSoftObjectPtr<UDataTable> FootballDataTableRef;
};
