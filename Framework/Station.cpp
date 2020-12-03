#include "stdafx.h"
#include "Station.h"
#include "Scene.h"

Station::Station(const wchar_t* path)
	: GameObject(path) {

}

Station::Station(bool is) : GameObject(L"resources/Station.png"), is(is)
{
	col = new AABBCollider(this, renderer);
	tag = Tag::Station;
	Scene::PushOnCurrentScene(col);

}

Station::Station(Player* player) : GameObject(L"resources/Station.png") {
	this->player = player;
	//this->player2 = nullptr;
}

Station::Station(Player2* player) : GameObject(L"resources/Station.png") {
	this->player2 = player;
	this->player = nullptr;
}

Station::~Station()
{

}

void Station::Update()
{
	if (player->transform->position.y >= transform->position.y + 1000) {
		transform->position.y += 5000.f;
		is = false;
	}

	if (player->transform->position.y >= transform->position.y - 350
		&& player->transform->position.y <= transform->position.y + 350)
		if (!player->isMove && !is)
		{
			ScoreManager::AddScore(100);
			is = true;
		}
}

void Station::OnCollision(GameObject* other) {
	//if (other->tag == Tag::Player) {
	//	if (!((Player*)other)->isMove)
	//		ScoreManager::AddScore(100);
	//}
}