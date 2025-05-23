#include "Framework.h"
#include "StartScene.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{
}

void StartScene::Update()
{
	if (Input::Get()->IsKeyDown(VK_F1))
	{
		SCENE->ChangeScene("Play");
	}
}

void StartScene::Render()
{

}
