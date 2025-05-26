#include "Framework.h"
#include "LifeManager.h"

LifeManager::LifeManager()
{
	lifes.resize(LIFE_POOL_SIZE);

	for (Life*& life : lifes)
	{
		life = new Life();
		position += {life->Radius(), 0};
		life->SetLocalPosition(position);
		position += {life->Radius()+3, 0};
		life->SetActive(false);
	}
	
	for (int i = 0; i < lifeSize && i < lifes.size(); i++)
	{
		lifes[i]->SetActive(true);
	}
}

LifeManager::~LifeManager()
{
	for (Life* life : lifes)
	{
		delete life;
	}
	lifes.clear();
}

void LifeManager::Update()
{
	for (Life* life : lifes)
	{
		if (!life->IsActive())
		{
			continue;
		}
		life->SetActive(false);
	}
	for (int i = 0; i < lifeSize && i < lifes.size(); i++)
	{
		lifes[i]->SetActive(true);
	}
	for (Life* life : lifes)
	{
		if (!life->IsActive())
		{
			continue;
		}
		life->Update();
	}
}

void LifeManager::Render()
{
	for (Life* life : lifes)
	{
		if (!life->IsActive())
		{
			continue;
		}
		life->Render();
	}
}
