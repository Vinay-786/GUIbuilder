#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class guiClass {
   public:
    void Init(GLFWwindow* window, const char* glsl_version);
    void NewFrame();
    virtual void Update();
    void Render(GLFWwindow* window);
    void Shutdown();
};
