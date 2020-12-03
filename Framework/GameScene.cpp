#include "stdafx.h"
#include "GameScene.h"

void GameScene::Initialize()
{	
	player1 = new Player();
	player1->transform->SetPosition(-100, 0);
	player1->transform->SetScale(0.5, 0.5);

	player2 = new Player2();
	player2->transform->SetPosition(100, 0);
	player2->transform->SetScale(0.5, 0.5);

	background = new BackGroundImage(player1);
	background->transform->SetPosition(0, 0);

	background2 = new BackGroundImage(player2);
	background2->transform->SetPosition(0, 0);

	Push(background);
	Push(background2);

	Push(player1);
	Push(player2);

	station = new Station(player1);
	Push(station);
	station->transform->SetPosition(-200, 1000);

	subScreen = new SubScreen(Vector2(850.0f, 1080.0f), GetD2DApp());
	subScreen->transform->SetPosition(1435.0f,540.0f);
	subScreen->target = player2->transform;
	Push(subScreen);

	PushUI(new ScoreManager());
}