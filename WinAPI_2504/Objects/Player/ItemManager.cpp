#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (Item*& item : items)
	{
		item = new Item;
		item->SetActive(false);

		int randomStatus = rand() % (int)ItemStatus::ItemStatusEnd;
		item->SetItemStatus((ItemStatus)randomStatus);
	}
}

ItemManager::~ItemManager()
{
	for (Item* item : items)
	{
		delete item;
	}
}

void ItemManager::CollisionPlayer(Item* item, Player* player)
{
	if (item->IsRectCollision(player, nullptr))
	{
		item->SetActive(false);
		switch (item->GetItemStatus())
		{
		case ItemStatus::AddBallSpeed:
		{
			BallManager::Get()->AddSpeed();
		}
		break;

		case ItemStatus::GetLife:
		{
			int life = LifeManager::Get()->GetLifeSize();
			LifeManager::Get()->SetLifeSize(life + 1);
		}
		break;

		case ItemStatus::GetBall:
		{
			BallManager::Get()->AddBall();
		}
		break;

		case ItemStatus::AddPlayerSpeed:
		{
			player->AddSpeed(30);
		}
		break;
		}
	}
}

void ItemManager::Update(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsActive())
			continue;
		item->Update();
		CollisionPlayer(item,player);
		if (item->GetGlobalPosition().y < 0)
			item->SetActive(false);
	}
}

void ItemManager::Render()
{
	for (Item* item : items)
	{
		if (!item->IsActive())
			continue;
		item->Render();
	}
}

void ItemManager::ActiveItem(Vector2 pos)
{
	for (Item* item : items)
	{
		if (item->IsActive())
			continue;
		item->SetActive(true);
		item->SetLocalPosition(pos);
		break;
	}
}

void ItemManager::AllSetFalse()
{
	for (Item* item : items)
	{
		item->SetActive(false);
		break;
	}
}
