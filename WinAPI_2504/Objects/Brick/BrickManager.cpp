#include "Framework.h"

BrickManager::BrickManager()
{
	bricks.resize(BRICK_POOL_SIZE);
	int count = 0;
	for (Brick*& brick : bricks)
	{
		brick = new Brick;

		brick->SetActive(true);
		brick->SetColorType(brick->ColorType::Red);
		brick->SetHP((int)brick->ColorType::Red);
		position += {brick->Size().x * 0.5f , 0};
		brick->SetLocalPosition(position);
		count++;
		if (count == 10)
		{
			position -= {0, brick->Size().y+10};
			position.x = 0;
			count = 0;
			continue;
		}
		position += {brick->Size().x * 0.5f + 5, 0};

	}
}

BrickManager::~BrickManager()
{
	for (Brick* brick : bricks)
	{
		delete brick;
	}
	bricks.clear();
}

void BrickManager::Update()
{
	for (Brick* brick : bricks)
	{
		brick->Update();
	}
}

void BrickManager::Render()
{
	for (Brick* brick : bricks)
	{
		brick->Render();
	}
}

void BrickManager::BrickCollision(Ball*& ball)
{
	for (Brick* brick : bricks)
	{
		if (!brick->IsActive())
			continue;
		bool collision = BallManager::Get()->RectCollision(ball, (RectCollider*&)brick);

		if (collision)
		{
			brick->SetHP(brick->GetHP()-1);
			if (brick->GetHP() == 0)
				brick->SetActive(false);
		}
	}
}
