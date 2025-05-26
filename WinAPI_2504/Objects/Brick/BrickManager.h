#pragma once

class BrickManager : public Singleton<BrickManager>
{
	friend class Singleton;
private:
	const int BRICK_POOL_SIZE = 100;

private:
	BrickManager();
	~BrickManager();

public:
	void Update();
	void Render();

	void BrickCollision(Ball*& ball);
private:
	Vector2 position = { 0,SCREEN_HEIGHT - 15 };
	vector<Brick*> bricks;
};