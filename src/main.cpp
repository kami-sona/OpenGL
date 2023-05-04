#include "WindowInfo.h"
#include "DT_Window.h"
#include "Shader.h"
#include "UsrImgui.h"


int main()
{
	glfwInit();

	DT_Window window(800, 600);
	window.SetBufferFresh();

	UsrImgui a(window.GetWindow(),"#version 130");


	ShaderProgram P;
	VertexShader V("resource/vertexShaderCode.vert");
	FragShader F("resource/fragShaderCode.frag");
	V.Compile(P);
	F.Compile(P);
	P.use();
	a.Init();


	while (!window.IsClose())
	{

		a.NewFrame();

		
		a.Update();
		a.Render();
		window.SwapBuffer();
		window.PollEvents();
	}


	a.Shutdown();
	glfwTerminate();

	return 0;
}