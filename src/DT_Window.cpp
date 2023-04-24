#include "DT_Window.h"



DT_Window::DT_Window(int width, int height, string name, GLFWmonitor* monitor, GLFWwindow* share)
{
	glfwInit();

	CWindow = glfwCreateWindow(width, height, name.c_str(), monitor,share);

	if (!CWindow)
		throw "Can't create window";

	glfwMakeContextCurrent(CWindow);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw "Can't load glad pointer";
	}

}

DT_Window::~DT_Window()
{
	if (CWindow)
		glfwDestroyWindow(CWindow);
}

bool DT_Window::IsClose() const
{
	return glfwWindowShouldClose(CWindow);
}

void DT_Window::SwapBuffer() const
{
	glfwSwapBuffers(CWindow);
}

void DT_Window::PollEvents() const
{
	glfwPollEvents();
}
