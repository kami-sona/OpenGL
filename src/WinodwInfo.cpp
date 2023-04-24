#include "WindowInfo.h"

void GF_BindStd::framesize_callback(GLFWwindow* window, int width, int height)
{
	if (!window)
	{
		glViewport(0, 0, width, height);
	}
}
