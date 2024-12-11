#include "guiClass.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

void guiClass::Init( GLFWwindow * window, const char * glsl_version )
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO & io = ImGui::GetIO();

    // Setup PlatForm/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL( window, true );
    ImGui_ImplOpenGL3_Init( glsl_version );
    ImGui::StyleColorsDark();
}
void guiClass::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void render_conan_logo()
{
    ImDrawList * draw_list = ImGui::GetWindowDrawList();
    float sz               = 300.0f;
    static ImVec4 col1     = ImVec4( 68.0 / 255.0, 83.0 / 255.0, 89.0 / 255.0, 1.0f );
    static ImVec4 col2     = ImVec4( 40.0 / 255.0, 60.0 / 255.0, 80.0 / 255.0, 1.0f );
    static ImVec4 col3     = ImVec4( 50.0 / 255.0, 65.0 / 255.0, 82.0 / 255.0, 1.0f );
    static ImVec4 col4     = ImVec4( 20.0 / 255.0, 40.0 / 255.0, 60.0 / 255.0, 1.0f );
    const ImVec2 p         = ImGui::GetCursorScreenPos();
    float x = p.x + 4.0f, y = p.y + 4.0f;
    draw_list->AddQuadFilled(
        ImVec2( x, y + 0.25 * sz ), ImVec2( x + 0.5 * sz, y + 0.5 * sz ), ImVec2( x + sz, y + 0.25 * sz ),
        ImVec2( x + 0.5 * sz, y ), ImColor( col1 ) );
    draw_list->AddQuadFilled(
        ImVec2( x, y + 0.25 * sz ), ImVec2( x + 0.5 * sz, y + 0.5 * sz ), ImVec2( x + 0.5 * sz, y + 1.0 * sz ),
        ImVec2( x, y + 0.75 * sz ), ImColor( col2 ) );
    draw_list->AddQuadFilled(
        ImVec2( x + 0.5 * sz, y + 0.5 * sz ), ImVec2( x + sz, y + 0.25 * sz ), ImVec2( x + sz, y + 0.75 * sz ),
        ImVec2( x + 0.5 * sz, y + 1.0 * sz ), ImColor( col3 ) );
    draw_list->AddLine(
        ImVec2( x + 0.75 * sz, y + 0.375 * sz ), ImVec2( x + 0.75 * sz, y + 0.875 * sz ), ImColor( col4 ) );
}
void guiClass::Update()
{
    // render you GUI
    ImGui::Begin( "Conan logo" );
    render_conan_logo();
    ImGui::End();
}
void guiClass::Render()
{
    // render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
}
void guiClass::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
