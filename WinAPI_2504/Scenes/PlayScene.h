#pragma once

class PlayScene :public Scene
{
public :
	PlayScene();
	~PlayScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

private:
	Player* player;
	Ball* ball;
};