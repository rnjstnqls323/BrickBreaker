#pragma once

class Player : public RectCollider
{
private:
	const Vector2 SPAWN_POINT = { 200.0f,200.0f };
public:
	Player();
	~Player();

	void Update();

private:
	void MakeMesh() override;
	void Move();

private:
	Vector2 halfSize = size * 0.5f;
	Vector2 localPosition;
	int speed = 200.0f;
};