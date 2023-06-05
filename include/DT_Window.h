#pragma once
#include "WindowInfo.h"
#include "DT_File.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
class DT_Window //This class is to conduct a window 
{
public:

	DT_Window(int width,int height,string name = "window",GLFWmonitor * monitor = nullptr, GLFWwindow* share = nullptr);

	~DT_Window();

	GLFWwindow* GetWindow()const;

	bool IsClose() const;

	void SwapBuffer()const;

	void PollEvents() const;

	void SetBufferFresh()const;

	void SetInputFresh() const;
private:

	GLFWwindow* CWindow;
};

