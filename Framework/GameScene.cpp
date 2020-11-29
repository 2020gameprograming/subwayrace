#include "stdafx.h"
#include "GameScene.h"

void GameScene::Initialize()
{
	background = new GameObject(L"resources/Gbackground.png");
	Push(background);
	background->transform->SetPosition(0, 4500);
	

	background2 = new GameObject(L"resources/Gbackground.png");
	Push(background2);
	background2->transform->SetPosition(0, 14740);

	station = new GameObject(L"resources/station.png");
	Push(station);
	station->transform->SetPosition(0, 5000);


	player1 = new Player();
	Push(player1);
	player1->transform->SetPosition(-100, 0);
	player1->transform->SetScale(0.5, 0.5);


	player2 = new Player2();
	Push(player2);
	player2->transform->SetPosition(100, 0);
	player2->transform->SetScale(0.5, 0.5);


}

void GameScene::Update()
{
	
}