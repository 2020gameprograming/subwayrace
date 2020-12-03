#include "stdafx.h"
#include "BackGroundImage.h"

BackGroundImage::BackGroundImage(Player* onPlayer) : GameObject(L"resources/Gbackground.png"), player(onPlayer), player2(nullptr)
{
	tag = Tag::basic;
}

BackGroundImage::BackGroundImage(Player2* onPlayer) : GameObject(L"resources/Gbackground.png"), player2(onPlayer), player(nullptr)
{
	tag = Tag::basic;
}

void BackGroundImage::Update()
{
	if (!player2) {
		if (player->transform->position.y >= transform->position.y) {
			transform->position.y += 2560.f;
		}
	}
	else if (!player) {
		if (player2->transform->position.y >= transform->position.y) {
			transform->position.y += 2560.f;
		}
	}
	
}
