#pragma once

class StartScene :public Scene
{
public :
	StartScene();
	~StartScene();

	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render() override;

};