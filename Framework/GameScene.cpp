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

	station = new Station();
	Push(station);
	station->transform->SetPosition(-200, 5000);


	player1 = new Player();
	Push(player1);
	player1->transform->SetPosition(-100, 0);
	player1->transform->SetScale(0.5, 0.5);


	player2 = new Player2();
	Push(player2);
	player2->transform->SetPosition(100, 0);
	player2->transform->SetScale(0.5, 0.5);

	subScreen = new SubScreen(Vector2(850.0f, 1080.0f), GetD2DApp());
	subScreen->transform->SetPosition(1435.0f,540.0f);
	subScreen->target = player2->transform;
	Push(subScreen);

	PushUI(new ScoreManager());
}

void GameScene::Update()
{
	std::cout << "업데이트" << std::endl;
}