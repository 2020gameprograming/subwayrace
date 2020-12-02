#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"
#include "SubScreen.h"
#include "Station.h"
#include "ScoreManager.h"
class GameScene :
    public Scene
{
public:
    Player* player1;
    Player2* player2;
    GameObject* background;
	GameObject* background2;
	Station* station;
    void Initialize();
    void Update();

};

