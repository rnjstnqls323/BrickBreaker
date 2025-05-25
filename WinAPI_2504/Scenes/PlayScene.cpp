#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	player = new Player;
	ball = new Ball;
}

PlayScene::~PlayScene()
{
	delete player;
	delete ball;
}

void PlayScene::Update()
{
	player->Update();
	ball->Update();
}

void PlayScene::Render()
{
	player->Render();
	ball->Render();
}
