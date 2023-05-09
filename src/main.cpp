#include "WindowInfo.h"
#include "DT_Window.h"
#include "Shader.h"
#include "UsrImgui.h"
#include "DT_VertexCore.h"


int main()
{
	glfwInit();

	DT_Window window(800, 600);
	window.SetBufferFresh();

	UsrImgui imgui_window(window.GetWindow(),"#version 130");

	vector<vector<float>> San =
	{
		{0.2f,0.0f,0.0f, 1.0f,0.0f,0.0f},
		{0.0f,0.2f,0.0f, 0.0f,1.0f,0.0f},
		{-0.2f,0.0f,0.0f, 0.0f,0.0f,1.0f}
	};

	float San2[] =
	{
		0.2f,0.0f,0.0f, 1.0f,0.0f,0.0f,
		0.3f,0.2f,0.0f, 0.0f,1.0f,0.0f,
		0.4f,0.0f,0.0f, 0.0f,0.0f,1.0f
	};

	VBO a(&San);


	ShaderProgram P;
	VertexShader V("resource/vertexShaderCode.vert");
	FragShader F("resource/fragShaderCode.frag");
	V.Compile(P);
	F.Compile(P);
	P.use();


	imgui_window.Init();


	while (!window.IsClose())
	{
		imgui_window.NewFrame();

		glClear(GL_COLOR_BUFFER_BIT);
		a.Draw();
		
		imgui_window.Update();
		imgui_window.Render();
		window.SwapBuffer();
		window.PollEvents();
	}


	imgui_window.Shutdown();
	glfwTerminate();

	return 0;
}