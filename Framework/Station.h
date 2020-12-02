#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Station :
	public GameObject
{
public:
	Station();
	~Station();
	bool is;
	void Update();
	AABBCollider* col;
	void OnCollision(GameObject* other);
};

