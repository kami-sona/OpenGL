#pragma once
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

class UsrImgui
{
public:
	UsrImgui(GLFWwindow* winodw,const char*gl_version);
	void Init();
	void Update();
	void Render();
	void NewFrame();
	void Shutdown();

	float Mix = 0;
	float Angle = 0;

private:
	
	GLFWwindow* cwindow;
	const char* glsl_version;
};

