#include "stdafx.h"
#include "Station.h"
#include "Scene.h"

Station::Station() : GameObject(L"resources/Station.png"), is(false)
{
	col = new AABBCollider(this, renderer);
	tag = Tag::Station;
	Scene::PushOnCurrentScene(col);

}	

Station::~Station()
{

}

void Station::Update()
{
}

void Station::OnCollision(GameObject* other) 
{
}
