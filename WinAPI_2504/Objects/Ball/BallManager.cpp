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

void BallManager::Update(Player* player)
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
 		ball->Update();
		BarCollision(ball, player);
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

void BallManager::BarCollision(Ball*& ball, Player*& player)
{

	Vector2 overlap;

	bool isCollision = ball->IsRectCollision(player, &overlap);
	if (!isCollision)
		return;

	ball->ChangeCrashDirection(overlap);
}
