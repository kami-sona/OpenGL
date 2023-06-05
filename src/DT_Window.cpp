#include "DT_Window.h"



DT_Window::DT_Window(int width, int height, string name, GLFWmonitor* monitor, GLFWwindow* share)
{

	CWindow = glfwCreateWindow(width, height, name.c_str(), monitor,share);

	if (!CWindow)
		throw "Can't create window";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

GLFWwindow* DT_Window::GetWindow() const
{
	return CWindow;
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

void DT_Window::SetBufferFresh() const
{
	glfwSetFramebufferSizeCallback(CWindow, GF_BindStd::framesize_callback);
}

void DT_Window::SetInputFresh() const
{
	glfwSetKeyCallback(CWindow, GF_BindStd::process_input);
}
