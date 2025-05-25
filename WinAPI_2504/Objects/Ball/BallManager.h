#pragma once

class BallManager : public Singleton<BallManager>
{
	friend class Singleton;
private:
	const int BALL_POOL_SIZE = 5;
private:
	BallManager();
	~BallManager();

public:
	void Update(Player* player);
	void PushSpace(Vector2 pos);
	void Render();

private:
	void BarCollision(Ball*& ball, Player*& player);

private:
	vector<Ball*> balls;
};