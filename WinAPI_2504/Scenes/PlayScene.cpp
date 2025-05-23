#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	player = new Player;
}

PlayScene::~PlayScene()
{
	delete player;
}

void PlayScene::Update()
{
	player->UpdateWorld();
}

void PlayScene::Render()
{
	player->Render();
}
