#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Player.h"
#include "Player2.h"
#include "ScoreManager.h"

class Station :
	public GameObject
{
public:
	Station(const wchar_t* path);
	Station(bool is);
	Station(Player* player);
	Station(Player2* player2);
	~Station();
	bool is;
	void Update();
	AABBCollider* col;
	void OnCollision(GameObject* other);
	Player* player;
	Player2* player2;
};

