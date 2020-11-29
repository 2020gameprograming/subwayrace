#include "stdafx.h"
#include "Player.h"
#include "TimeManager.h"


Player::Player() :GameObject(L"resources/Player1.png"), moveSpeed(300.0f), moveForce(1.0f), maxForce(15.0f)
{

}


Player::~Player() 
{

}

void Player::Update() 
{
	Move();
	std::cout << moveSpeed * moveForce << std::endl;
}

void Player::Move() 
{
	Vector2 input;
	if (InputManager::GetKeyDown(VK_SPACE)) {
		isMove = true;
	}
	if (isMove)
		input.y += 1.0f;
	if (InputManager::GetKeyPressed(VK_SPACE)) {

		if (moveForce < maxForce)
			moveForce = moveForce * 1.01;
	}
	if (InputManager::GetKeyPressed(VK_LSHIFT)) {
		if (moveForce > 0.1)
			moveForce = moveForce * 0.95;
		else {
			moveForce = 0;
			isMove = false;
		}
	}
	if (InputManager::GetKeyUp(VK_LSHIFT))
		moveForce = 1;
	if (input.y != 0.0f) {

		input = input.normalized();
		transform->position.y += moveSpeed * moveForce * input.y * TimeManager::GetDeltaTime();
	}
}

