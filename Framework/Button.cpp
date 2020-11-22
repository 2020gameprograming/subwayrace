#include "stdafx.h"
#include "Button.h"
#include "Scene.h"
#include "GameScene.h"

Button::Button(const wchar_t* path) : GameObject(path)
{
}

Button::~Button()
{
}

void Button::Update()
{
	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		int mx = InputManager::GetMouseX();
		int my = InputManager::GetMouseY();

		if (mx >= 960 - 130 && mx <= 960 + 130 &&
			my >= 640 - 50 && my <= 640 + 50)
			Scene::ChangeScene(new GameScene());

		if (mx >= 960 - 130 && mx <= 960 + 130 &&
			my >= 840 - 50 && my <= 840 + 50)
			exit(0);

			
	}
}
