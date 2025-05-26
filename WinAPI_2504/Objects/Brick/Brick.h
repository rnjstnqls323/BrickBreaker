#pragma once

enum ColorType {
	None,
	Red,
	Orange,
	Yellow,
	Green,
	Gray,
	ColorEnd
};

class Brick :public RectCollider
{
private:
	const int BRICK_WIDTH = 68;
	const int BRICK_HEIGHT = 30;

public:

	Brick();
	~Brick();

	void Update();
	void SettingColor(ColorType color);

	void SetHP(int healthPoint) { this->healthPoint = healthPoint; }
	int GetHP() { return healthPoint; }

	void SetColorType(ColorType type) { this->type = type; }
	ColorType GetColorType() { return type; }
private:
	void MakeMesh() override;

private:
	int healthPoint = 0;

	Vector2 halfSize;
	ColorType type = None;
};