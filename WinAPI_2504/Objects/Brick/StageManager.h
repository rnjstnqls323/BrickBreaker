#pragma once

class StageManager :public Singleton<StageManager>
{
	friend class Singleton;
private:
	const int MAX_STAGE = 3;
private:
	StageManager();
	~StageManager();

public:
	void UpdateStage();

private:
	int stage = 1;

	unordered_map<int, string> stagePath;
};