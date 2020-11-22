#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "Button.h"

class MainScene :
    public Scene
{
public:
    GameObject* background;
    GameObject* title;
    GameObject* startbutton;
    GameObject* exitbutton;
    void Initialize();
};

