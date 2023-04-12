#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>


int main()
{
	glfwInit();

	GLFWwindow* windows = glfwCreateWindow(800, 600, "OpenGL",nullptr, nullptr);

	glfwMakeContextCurrent(windows);
	

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "load pointer failed" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(windows))
	{
		glClearColor(1.0f, 1.0f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(windows);
		glfwPollEvents();
	}

	glfwDestroyWindow(windows);
	glfwTerminate();

	system("pause");
}