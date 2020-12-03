#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Player2.h"

class BackGroundImage :
    public GameObject
{
public:
    Player* player;
    Player2* player2;


    BackGroundImage(Player* onPlayer);
    BackGroundImage(Player2* onPlayer);
    void Update();
};

