#pragma once

struct BrickData
{
	int key;
	ColorType color;
	int healthPoint;

};

class BrickDataManager : public Singleton<BrickDataManager>
{
	friend class Singleton;

private:
	BrickDataManager();
	~BrickDataManager();

public:
	void LoadData(const string& fileName);

	BrickData GetBrick(int key) { return brickDatas[key]; }

private:
	unordered_map<int, BrickData> brickDatas;
};