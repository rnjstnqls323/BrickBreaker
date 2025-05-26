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
	void Update(RectCollider* rect);
	void PushSpace(Vector2 pos);
	void Render();
	void SetBallStart();

	bool RectCollision(Ball*& ball, RectCollider*& rect);

private:
	vector<Ball*> balls;
};