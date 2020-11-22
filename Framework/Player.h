#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
    Player();
    ~Player();
    void Update();
    void Move();
    float moveSpeed;
    float moveForce;
    float maxForce;
};

