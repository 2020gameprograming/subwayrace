#include "stdafx.h"
#include "Camera.h"
#include "Scene.h"

#include "InputManager.h"
#include "TimeManager.h"
#include "Player.h"
#include "GameScene.h"
Camera::Camera()
{
	screenWidth = WinApp::GetScreenWidthF();
	screenHeight = WinApp::GetScreenHeightF();
	halfWidth = screenWidth * 0.5f;
	halfHeight = screenHeight * 0.5f;
	moveSpeed=300.0f; 
	moveForce=1.0f; 
	maxForce=15.0f;
	isMove = false;
	



	screenBox = new AABBCollider(this, -halfWidth,  -halfHeight, halfWidth, halfHeight);
	//printf("w: %f, h: %f\n", halfWidth, halfHeight);
}

Camera::~Camera()
{
	SAFE_DELETE(screenBox);
}

Vector2 Camera::WorldPositionToScreen(const Vector2& worldPos)
{
	//piw: 월드 포지션
	//cp: 카메라 포지션
	//ss: 화면 크기(가로,세로)
	//pis: 스크린 포지션
	//piw - cp + ss/2 = pis

	//y축이 위를 향할경우
	Camera* current = Camera::GetCamera();
	return Vector2(
		current->halfWidth - worldPos.x + current->transform->position.x,
		current->halfHeight - worldPos.y + current->transform->position.y
	);
	//y축이 아래를 향할경우
	//return Vector2(
	//	worldPos.x - transform->position.x + halfWidth * 0.5f,
	//	worldPos.y - transform->position.x + halfWidth * 0.5f);
}

Vector2 Camera::ScreenPositionToWorld(const Vector2& screenPos)
{
	//월드투스크린이랑 반대로하면됨

	//y축이 위를 향할경우
	Camera* current = Camera::GetCamera();
	return Vector2(
		screenPos.x - current->halfWidth + current->transform->position.x,
		current->halfHeight - screenPos.y + current->transform->position.y
	);

	//y축이 아래를 향할경우
	/*return Vector2(
		screenPos.x - halfWidth + transform->position.x,
		screenPos.y - halfHeight + transform->position.y
		);*/
}

bool Camera::IsOnScreen(AABBCollider* col)
{
	return CollisionManager::Intersected(col, screenBox);
}

Camera* Camera::GetCamera()
{
	return Scene::GetCurrentScene()->GetCamera();
}

void Camera::Update()
{
	////움직임을 담당
	/*if (InputManager::GetKeyState('W'))
		transform->position.y += 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('S'))
		transform->position.y -= 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('D'))
		transform->position.x += 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('A'))
		transform->position.x -= 100.0f * TimeManager::GetDeltaTime();*/
	Move();
}


void Camera::Move() 
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