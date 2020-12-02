#pragma once
#include "GameObject.h"
#include "Station.h"
#include "AABBCollider.h"
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
	int score;
    bool isMove;
	void OnCollision(GameObject* other);
	Station* CurrentStation;
	AABBCollider* col;
};

