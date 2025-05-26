#include "Framework.h"

StageManager::StageManager()
{
	for (int i = 1;i <= MAX_STAGE;i++)
	{
		stagePath[i] = ( "Resources/Tables/StageData" + to_string(i) + ".csv");
	}
	DataManager::Get()->LoadData(stagePath[stage]);
}

StageManager::~StageManager()
{
}

void StageManager::UpdateStage()
{
	stage++;
	if (stage > MAX_STAGE)
		return;
	DataManager::Get()->ClearData();
	DataManager::Get()->LoadData(stagePath[stage]);
	BallManager::Get()->BallClear();
	ItemManager::Get()->AllSetFalse();
}
