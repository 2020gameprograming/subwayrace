#include "stdafx.h"
#include "Player.h"
#include "TimeManager.h"
#include "Scene.h"
#include "ScoreManager.h"

Player::Player() :GameObject(L"resources/Player1.png"), moveSpeed(300.0f), moveForce(1.0f), maxForce(15.0f), isMove(false), score(0)
{
	col = new AABBCollider(this, renderer);
	Scene::PushOnCurrentScene(col);
	tag = Tag::Player;
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
		if (moveForce > 0.2)
			moveForce = moveForce * 0.95;
		else {
			moveForce = 0;
			isMove = false;
		}
	}
	if (InputManager::GetKeyUp(VK_LSHIFT)&&!isMove)
		moveForce = 1;
	if (input.y != 0.0f) {

		input = input.normalized();
		transform->position.y += moveSpeed * moveForce * input.y * TimeManager::GetDeltaTime();
	}
}



void Player::OnCollision(GameObject* other) {
	if (other->tag == Tag::Station) {
		CurrentStation = (Station*)other;
		if (!isMove&&!CurrentStation->is)
		{
			score += 100;
			ScoreManager::AddScore(100);
			CurrentStation->is = true;
		}
	}
}