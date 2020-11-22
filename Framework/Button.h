#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Button :
    public GameObject
{
public:
    Button(const wchar_t* path);
    ~Button();

    virtual void Update();
};

