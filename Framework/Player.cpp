#include "stdafx.h"
#include "Player.h"
#include "TimeManager.h"


Player::Player() :GameObject(L"resources/Player1.png"), moveSpeed(300.0f), moveForce(1.0f), maxForce(30.0f)
{

}


Player::~Player() 
{

}

void Player::Update() 
{
	Move();
}

void Player::Move() 
{
	Vector2 input;
	if (InputManager::GetKeyPressed(VK_SPACE)) {
		input.y += 1.0f;
		if(moveForce<maxForce)
			moveForce = moveForce * 1.1;
	}
	if (InputManager::GetKeyUp(VK_SPACE))
		moveForce = 1;
	if (input.y != 0.0f) {
		if (transform->position.y > 500)
			transform->position.y = -500;
		input = input.normalized();
		transform->position.y += moveSpeed * moveForce * input.y * TimeManager::GetDeltaTime();
	}
}