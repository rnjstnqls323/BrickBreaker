#include "Framework.h"

BallManager::BallManager()
{
	balls.resize(BALL_POOL_SIZE);
	for (Ball*& ball : balls)
	{
		ball = new Ball;
		ball->SetActive(false);
	}
	balls[0]->SetActive(true);
}

BallManager::~BallManager()
{
	for (Ball* ball : balls)
	{
		delete ball;
	}
	balls.clear();
}

void BallManager::Update(RectCollider* rect)
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
 		ball->Update();
		RectCollision(ball, rect);
		BrickManager::Get()->BrickCollision(ball);
	}
}

void BallManager::PushSpace(Vector2 pos)
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
		if (ball->IsMove() == false)
			ball->ChangeSpawn(pos);
	}
}

void BallManager::Render()
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
		ball->Render();
	}
}

bool BallManager::RectCollision(Ball*& ball, RectCollider*& rect)
{

	Vector2 overlap;

	bool isCollision = ball->IsRectCollision(rect, &overlap);
	if (!isCollision)
		return false;

	ball->ChangeCrashDirection(overlap);
	return true;
}
