#pragma once

#include <imgui.h>
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl3.h"
#include <stdio.h>

#define GL_SILENCE_DEPRACATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

class UseImGui
{
public:
    void Init(GLFWwindow* window, const char* glsl_version);
    void NewFrame();
    virtual void Update();
    void Render();
    void Shutdown();
};
