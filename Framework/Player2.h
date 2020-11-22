#pragma once
#include "GameObject.h"
class Player2 :
    public GameObject
{
public:
    Player2();
    ~Player2();
    void Update();
    void Move();
    float moveSpeed;
};

