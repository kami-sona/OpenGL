#include "WindowInfo.h"
#include "DT_Window.h"

int main()
{
	glfwInit();

	DT_Window window(800, 600);



	while (!window.IsClose())
	{
		glClearColor(1.0f, 1.0f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.SwapBuffer();
		window.PollEvents();
	}

	glfwTerminate();
	system("pause");
}