#pragma once

class BrickManager : public Singleton<BrickManager>
{
	friend class Singleton;
private:
	const int BRICK_POOL_SIZE = 100;

private:
	BrickManager();
	~BrickManager();

	void SettingBrick(Brick*& brick);
	bool CheckClear();

public:
	void Update();
	void Render();

	void BrickCollision(Ball*& ball);


private:

	int stage = 1;

	Vector2 position = { 0,SCREEN_HEIGHT - 15 };
	vector<Brick*> bricks;
	queue<int> brickStage;

};