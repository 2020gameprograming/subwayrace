#include "stdafx.h"
#include "MainScene.h"

void MainScene::Initialize()
{
	background = new GameObject(L"resources/background.png");
	Push(background);
	background->transform->SetPosition(0, 0);

	title = new GameObject(L"resources/title.png");
	Push(title);
	title->transform->SetPosition(0, 300);
	title->transform->SetScale(2, 1.5);

	startbutton = new Button(L"resources/startbutton.png");
	Push(startbutton);
	startbutton->transform->SetPosition(0, -100); // (960, 640)

	exitbutton = new Button(L"resources/exitbutton.png"); // (920, 840)
	Push(exitbutton);
	exitbutton->transform->SetPosition(0, -300);
}