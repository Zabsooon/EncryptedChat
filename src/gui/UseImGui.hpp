#pragma once

#include "GLFW/glfw3.h"
#include <imgui.h>

class UseImGui
{
public:
    void Init();
    virtual void Update();
    void Render();
    void Shutdown();
};
