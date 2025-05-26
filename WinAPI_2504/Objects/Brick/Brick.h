#pragma once

class Brick :public RectCollider
{
	// ü��, ���� ���̰� ���� �ϰ� �Ŵ����� 10���� 5�� ��������� �� ������. �������� �ҷ��ͼ� 0�̸� ��Ƽ�� false, �������� ����������
	//����, ü�� �� ��������.
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