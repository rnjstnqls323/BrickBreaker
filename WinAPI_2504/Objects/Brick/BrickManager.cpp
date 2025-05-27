#include "Framework.h"

BrickManager::BrickManager()
{

	BrickDataManager::Get()->LoadData(BRICK_DATA_PATH);

	brickStage = DataManager::Get()->GetStage();

	bricks.resize(BRICK_POOL_SIZE);
	int count = 0;
	for (Brick*& brick : bricks)
	{
		brick = new Brick;

		brick->SetActive(false);
		position += {brick->Size().x * 0.5f , 0};
		brick->SetLocalPosition(position);
		SettingBrick(brick);
		if (brick->GetColorType() != None)
			brick->SetActive(true);
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

void BrickManager::SettingBrick(Brick*& brick)
{
	int key = 0;
	if (!brickStage.empty()) {
		 key= brickStage.front();  // ¾ÈÀü
		brickStage.pop();
	}
	BrickData data = BrickDataManager::Get()->GetBrick(key);

	brick->SetColorType(data.color);
	brick->SetHP(data.healthPoint);

	DataManager::Get()->ClearData();
}

bool BrickManager::CheckClear()
{
	for (Brick* brick : bricks)
	{
		if (brick->IsActive())
			return false;
	}
	return true;;
}

void BrickManager::Update()
{
	for (Brick* brick : bricks)
	{
		brick->Update();
	}
	if (CheckClear())
	{
		StageManager::Get()->UpdateStage();
		brickStage= DataManager::Get()->GetStage();
		for (Brick* brick : bricks)
		{
			SettingBrick(brick);
			if (brick->GetColorType() != None)
				brick->SetActive(true);
		}
		BallManager::Get()->SetBallStart();
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
		bool collision = BallManager::Get()->RectCollision(ball, (RectCollider*&)brick,"Brick");

		if (collision)
		{
			int brickColor = (int)brick->GetColorType() - 1;
			brick->SetHP(brick->GetHP()-1);
			if(brick->GetColorType() != Gray)
				brick->SetColorType((ColorType)brickColor);

			if (brick->GetHP() == 0) {
				int random = rand() % 2;
				if(random == 0)
					ItemManager::Get()->ActiveItem(brick->GetGlobalPosition());
				brick->SetActive(false);
			}

		}
	}
}
