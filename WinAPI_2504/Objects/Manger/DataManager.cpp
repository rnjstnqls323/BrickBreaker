#include "Framework.h"

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::LoadData(const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		return;
	}

	string line;
	getline(file, line);
	while (getline(file, line))
	{

		vector<string> data = Utility::SplitString(line, ",");

		for (int i = 0;i < 10;i++)
		{
			stageDatas.push(stoi(data[i]));
		}
	}
	file.close();
}
