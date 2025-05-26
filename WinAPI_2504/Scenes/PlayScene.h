#pragma once

class PlayScene :public Scene
{
public :
	PlayScene();
	~PlayScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	//void GUIRender();

private:
	Player* player;
	Brick* brick;
	Ball* ball;
	Life* life;
	Item* item;

	Vector2 overlap;
	Vector2 playerSpaceBall;
};