#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"
class GameScene :
    public Scene
{
public:
    Player* player1;
    Player2* player2;
    GameObject* background;
	GameObject* background2;
	GameObject* station;
    void Initialize();
    void Update();

};

