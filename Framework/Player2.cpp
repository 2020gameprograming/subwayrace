#include "stdafx.h"
#include "Player2.h"
#include "TimeManager.h"


Player2::Player2() :GameObject(L"resources/Player2.png"), moveSpeed(300.0f), maxForce(15.0f), moveForce(1.0f)
{
	tag = Tag::Player2;
}


Player2::~Player2()
{

}

void Player2::Update()
{
	Move();
}

void Player2::Move()
{
	Vector2 input;
	if (InputManager::GetKeyDown(VK_UP)) {
		isMove = true;
	}
	if (isMove)
		input.y += 1.0f;
	if (InputManager::GetKeyPressed(VK_UP)) {

		if (moveForce < maxForce)
			moveForce = moveForce * 1.01;
	}
	if (InputManager::GetKeyPressed(VK_RSHIFT)) {
		if (moveForce > 0.1)
			moveForce = moveForce * 0.95;
		else {
			moveForce = 0;
			isMove = false;
		}
	}
	if (InputManager::GetKeyUp(VK_RSHIFT)&&!isMove)
		moveForce = 1;
	if (input.y != 0.0f) {
		input = input.normalized();
		transform->position.y += moveSpeed * moveForce * input.y * TimeManager::GetDeltaTime();
	}
}