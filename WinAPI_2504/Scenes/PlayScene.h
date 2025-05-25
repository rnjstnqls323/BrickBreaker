#pragma once

class PlayScene :public Scene
{
public :
	PlayScene();
	~PlayScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render() override;
	//void GUIRender();

private:
	Player* player;

	Vector2 overlap;
	Vector2 playerSpaceBall;
};