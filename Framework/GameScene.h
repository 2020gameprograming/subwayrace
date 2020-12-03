#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"
#include "SubScreen.h"
#include "Station.h"
#include "ScoreManager.h"
#include "BackGroundImage.h"
class GameScene :
    public Scene
{
public:
    Player* player1;
    Player2* player2;
    BackGroundImage* background;
	BackGroundImage* background2;
	Station* station;
    Station* station2;
    void Initialize();

};

