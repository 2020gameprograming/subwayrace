#include "stdafx.h"
#include "GameScene.h"

void GameScene::Initialize()
{
	background = new GameObject(L"resources/Gbackground.png");
	Push(background);
	background->transform->SetPosition(0, 5100);


	player1 = new Player();
	Push(player1);
	player1->transform->SetPosition(-100, 0);
	player1->transform->SetScale(0.3, 0.3);

	player2 = new Player2();
	Push(player2);
	player2->transform->SetPosition(100, 0);
	player2->transform->SetScale(0.3, 0.3);


}

void GameScene::Update()
{

}