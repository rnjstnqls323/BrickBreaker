#pragma once

class StartScene :public Scene
{
public :
	StartScene();
	~StartScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;

	void Render() override;

};