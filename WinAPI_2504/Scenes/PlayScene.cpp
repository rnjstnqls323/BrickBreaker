#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	player = new Player;
	BallManager::Get();
	BrickManager::Get();
	//brick = new Brick;
	

	//brick->SetLocalPosition(100, 300);
	//brick->SetColorType(brick->ColorType::Red);
	playerSpaceBall = { 0,player->Size().y};
}

PlayScene::~PlayScene()
{
	delete player;
	BallManager::Delete();

	BrickManager::Delete();
}

void PlayScene::Update()
{
	player->Update();
	BallManager::Get()->PushSpace(player->GetLocalPosition() + playerSpaceBall);
	BallManager::Get()->Update(player);
	
	//brick->Update();
	BrickManager::Get()->Update();
}

void PlayScene::Render()
{
	player->Render();
	BallManager::Get()->Render();

	//brick->Render();
	BrickManager::Get()->Render();
}

//void PlayScene::GUIRender()
//{
//	brick->Edit();
//
//	ImGui::DragFloat2("Overlap", (float*)&overlap);
//}


