#include "stdafx.h"
#include "Player2.h"
#include "TimeManager.h"


Player2::Player2() :GameObject(L"resources/Player2.png"), moveSpeed(300.0f)
{

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
	if (InputManager::GetKeyPressed(VK_UP)) {
		input.y += 1.0f;
	}
	if (input.y != 0.0f) {
		input = input.normalized();
		transform->position.y += moveSpeed * input.y * TimeManager::GetDeltaTime();
	}
}