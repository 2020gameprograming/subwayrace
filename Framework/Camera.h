#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Camera :
	public GameObject
{
private:
	float screenWidth;
	float screenHeight;
	float halfWidth;
	float halfHeight;
	float moveSpeed;
	float moveForce;
	float maxForce;
	bool isMove;

	AABBCollider* screenBox;
public:
	Camera();
	virtual ~Camera();

	static Vector2 WorldPositionToScreen(const Vector2& worldPosition);
	static Vector2 ScreenPositionToWorld(const Vector2& screenPosition);
	bool IsOnScreen(AABBCollider* col);



	void Move();

public:
	static Camera* GetCamera();
	void Update();


};

