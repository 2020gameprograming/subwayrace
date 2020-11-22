#pragma once
#include "stdafx.h"
#include "tag.h"
#include "RenderInfo.h"
#include "InputManager.h"

class GameObject
{
public:
	GameObject(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	GameObject(const wchar_t* imagePath, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	GameObject(RenderInfo* renderInfo, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~GameObject();

public:
	bool isActive;
	Tag::Tag tag;
public:
	std::string name;
	Transform* transform;
	RenderInfo* renderer;

public:
	virtual void Start() {}				//������Ʈ�� ó�� ������� �� ȣ��
	virtual void Update() {}			//�� �����Ӹ��� ȣ��
	virtual void LateUpdate() {}		//Update�� ȣ��� ���� ȣ��
	virtual void OnDestroy() {}			//������Ʈ�� ������ �� ȣ��
	virtual void OnCollision(GameObject* other) {}		//�浹 �߿� ȣ��
};
