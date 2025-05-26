#pragma once

class ItemManager : public Singleton<ItemManager> {
	friend class Singleton;
	
private:
	const int ITEM_POOL_SIZE = 10;
private:
	ItemManager();
	~ItemManager();

	void CollisionPlayer(Item* item,Player* player);
public:
	void Update(Player* player);
	void Render();

	void ActiveItem(Vector2 pos);
	void AllSetFalse();

private:
	vector<Item*> items;

};