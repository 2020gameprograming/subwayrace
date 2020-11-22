#include "stdafx.h"
#include "GameScene.h"

void GameScene::Initialize()
{
	player1 = new Player();
	Push(player1);
	player1->transform->SetPosition(-100, 0);

	player2 = new Player2();
	Push(player2);
	player2->transform->SetPosition(100, 0);

}

void GameScene::Update()
{

}