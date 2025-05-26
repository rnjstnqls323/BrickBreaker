#pragma once

class Brick :public RectCollider
{
	// 체력, 눈에 보이게 구현 하고 매니저로 10개씩 5줄 만든다음에 다 꺼놓기. 엑셀파일 불러와서 0이면 액티브 false, 나머지면 엑셀정보로
	//색상, 체력 등 가져오기.
private:
	const int BRICK_WIDTH = 68;
	const int BRICK_HEIGHT = 30;

public:
	enum ColorType {
		None,
		Red,
		Orange,
		Yellow,
		Green,
		Gray,
		ColorEnd
	};


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