#pragma once

class LifeManager : public Singleton<LifeManager> {
	friend class Singleton;

private:
	const int LIFE_POOL_SIZE = 5;

private:
	LifeManager();
	~LifeManager();

public:
	void Update();
	void Render();

	void SetLifeSize(int size) { lifeSize = size; }
	int GetLifeSize() { return lifeSize; }
private:
	int lifeSize = 3;
	vector<Life*> lifes;
	Vector2 position = { 0 , SCREEN_HEIGHT-20 };
};