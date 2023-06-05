#include "WindowInfo.h"

void GF_BindStd::framesize_callback(GLFWwindow* window, int width, int height)
{
	if (window)
	{
		glViewport(0, 0, width, height);
	}
}

void GF_BindStd::process_input(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}
