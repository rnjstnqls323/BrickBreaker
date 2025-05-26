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
	ballNum++;
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

void BallManager::SetBallStart()
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
		ball->SetUpDirection();
		ball->SetIsMove(false);
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

void BallManager::AddSpeed()
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
		ball->AddSpeed(50);
	}
}

void BallManager::AddBall()
{
	if(ballNum<balls.size())
		balls[ballNum++]->SetActive(true);
}

void BallManager::BallClear()
{
	for (Ball* ball : balls)
	{
		if (!ball->IsActive())
			continue;
		ball->SetActive(false);
		ball->SetUpDirection();
		ball->SetIsMove(false);
	}
	ballNum = 0;
	balls[ballNum++]->SetActive(true);
}
