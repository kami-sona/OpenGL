#include "UsrImgui.h"

UsrImgui::UsrImgui(GLFWwindow* window,const char* gl_version)
{
    cwindow = window;
    glsl_version = gl_version;
}

void UsrImgui::Init()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(cwindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
}

void UsrImgui::Update()
{
    ImGui::Begin("Triangle Color");        
    ImGui::SliderFloat("MixValue", &Mix, 0, 1);
    ImGui::SliderFloat("Angle", &Angle, 0, 180);
    ImGui::End();
}

void UsrImgui::Render()
{
    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UsrImgui::NewFrame()
{
    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UsrImgui::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}


