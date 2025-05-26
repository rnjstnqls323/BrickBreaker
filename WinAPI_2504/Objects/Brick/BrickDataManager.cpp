#include "Framework.h"

BrickDataManager::BrickDataManager()
{
}

BrickDataManager::~BrickDataManager()
{
}

void BrickDataManager::LoadData(const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		//MessageBox(nullptr, L"Failed to open file", L"Error", MB_OK);
		return;
	}

	string line;

	getline(file, line);

	while (getline(file, line))
	{
		
		vector<string> data = Utility::SplitString(line, ",");

		BrickData brickData;
		brickData.key = stoi(data[0]);
		brickData.color = (ColorType)stoi(data[1]);
		brickData.healthPoint = stoi(data[2]);
		brickDatas[brickData.key] = brickData;
	}
	file.close();
}
