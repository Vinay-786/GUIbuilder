#include "guiClass.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

void guiClass::Init(GLFWwindow* window, const char* glsl_version) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Setup PlatForm/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();
}
void guiClass::NewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void guiClass::Update() {
    static float f = 0.0f;
    static int counter = 0;
    // render you GUI
    ImGui::Begin("Hello world!");
    ImGui::SetWindowFontScale(1.25);
    ImGui::Text("First I'm gui window");
    ImGui::SliderFloat("Float", &f, 0.0f, 1.0f);

    static float clear_color[3];
    ImGui::ColorEdit3("Clear color", (float*)&clear_color);

    if (ImGui::Button("Button")) {
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                ImGui::GetIO().Framerate);
    ImGui::End();
}
void guiClass::Render(GLFWwindow* window) {
    // render dear imgui into screen
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void guiClass::Shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
