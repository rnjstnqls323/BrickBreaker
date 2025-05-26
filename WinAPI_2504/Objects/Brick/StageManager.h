#pragma once

class StageManager :public Singleton<StageManager>
{
	friend class Singleton;
private:
	const int MAX_STAGE = 4;
private:
	StageManager();
	~StageManager();

public:
	void UpdateStage();

private:
	int stage = 4;

	unordered_map<int, string> stagePath;
};