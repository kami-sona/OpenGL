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


	unique_ptr<vector<vector<float>>> pos = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{0.5, 0.0, 0.0},
			{ 0.0,0.5,0.0 },
			{ -0.5,0.0,0.0 }
		}
	);
	
	unique_ptr<vector<vector<float>>> color = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{1.0, 0.0, 0.0},
			{ 0.0,1.0,0.0 },
			{ 0.0,0.0,1.0 }
	}
	);


	VAO vao;
	vao.ConverToVertex(pos, VERTEX_POS);
	vao.ConverToVertex(color, VERTEX_COLOR_POS);



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
		vao.Draw();
		
		imgui_window.Update();
		imgui_window.Render();
		window.SwapBuffer();
		window.PollEvents();
	}


	imgui_window.Shutdown();
	glfwTerminate();

	return 0;
}