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
    void Initialize();
    void Update();

};

