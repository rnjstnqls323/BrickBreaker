#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	player = new Player;
	BallManager::Get();

	playerSpaceBall = { 0,player->Size().y};
}

PlayScene::~PlayScene()
{
	delete player;
	BallManager::Delete();
}

void PlayScene::Update()
{
	player->Update();
	BallManager::Get()->PushSpace(player->GetLocalPosition() + playerSpaceBall);
	BallManager::Get()->Update(player);
}

void PlayScene::Render()
{
	player->Render();
	BallManager::Get()->Render();
}

//void PlayScene::GUIRender()
//{
//	ball->Edit();
//
//	ImGui::DragFloat2("Overlap", (float*)&overlap);
//}


