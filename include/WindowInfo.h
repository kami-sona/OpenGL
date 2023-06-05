#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace GF_BindStd
{
	void framesize_callback(GLFWwindow* window, int width, int height);
	void process_input(GLFWwindow* window, int key, int scancode, int action, int mods);
}