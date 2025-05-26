#pragma once

class DataManager : public Singleton<DataManager>
{
	friend class Singleton;

private:
	DataManager();
	~DataManager();

public:
	void LoadData(const string& fileName);
	
	queue<int> GetStage() { return stageDatas; }

	void ClearData() {
		while (!stageDatas.empty())
			stageDatas.pop();
	}

private:
	queue<int> stageDatas;

};