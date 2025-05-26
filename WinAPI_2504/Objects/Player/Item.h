#pragma once

enum ItemStatus
{
	GetLife,
	GetBall,
	AddBallSpeed,
	AddPlayerSpeed,
	ItemStatusEnd
};

class Item : public CircleCollider
{
private:
	const int VERTEX_SIZE = 64;
	const float SPEED = 200.0f;
public:
	Item();
	~Item();

	void Update();
	ItemStatus GetItemStatus() { return itemStatus; }
	void SetItemStatus(ItemStatus item) { itemStatus = item; }
private:
	void MakeMesh() override;
	void Move();
	
private:
	Vector2 direction = Vector2::Down();
	ItemStatus itemStatus = ItemStatusEnd;
};