#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	BrickDataManager::Get();
	DataManager::Get();
	StageManager::Get();
	LifeManager::Get();
	ItemManager::Get();

	player = new Player;
	BallManager::Get();
	BrickManager::Get();


	playerSpaceBall = { 0,player->Size().y};
}

PlayScene::~PlayScene()
{
	delete player;
	BallManager::Delete();

	BrickManager::Delete();

	BrickDataManager::Delete();
	DataManager::Delete();
	StageManager::Delete();
	LifeManager::Delete();
	ItemManager::Delete();

}

void PlayScene::Update()
{
	player->Update();
	BallManager::Get()->PushSpace(player->GetLocalPosition() + playerSpaceBall);
	BallManager::Get()->Update(player);
	BrickManager::Get()->Update();

	ItemManager::Get()->Update(player);
	LifeManager::Get()->Update();

	if (LifeManager::Get()->GetLifeSize() <= 0)
		SCENE->ChangeScene("Start");

}

void PlayScene::Render()
{
	player->Render();
	BallManager::Get()->Render();

	BrickManager::Get()->Render();

	LifeManager::Get()->Render();

	ItemManager::Get()->Render();

}

//void PlayScene::GUIRender()
//{
//	life->Edit();
//
//	ImGui::DragFloat2("Overlap", (float*)&overlap);
//}


