#include "WindowInfo.h"
#include "DT_Window.h"
#include "Shader.h"
#include "UsrImgui.h"
#include "DT_Mesh.h"

int main()
{
	glfwInit();

	DT_Window window(800, 600);
	window.SetBufferFresh();

	UsrImgui imgui_window(window.GetWindow(),"#version 130");


	unique_ptr<vector<vector<float>>> pos = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{0.5, 0.5, 0.0},
			{ -0.5,0.5,0.0 },
			{ -0.5,-0.5,0.0 },
			{0.5,-0.5,0.0,}
		}
	);
	
	unique_ptr<vector<vector<float>>> color = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{1.0, 0.0, 0.0},
			{ 0.0,1.0,0.0 },
			{ 0.0,0.0,1.0 },
			{1.0,0.0,0.0}
	}
	);

	unique_ptr<vector<vector<float>>> pos2 = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{0.5,0.0,0.0},
			{0.5,0.5,0.0},
			{1.0,0.0,0.0},
	}
	);





	DT_EboDataType index = make_unique<vector<unsigned int>>(
		initializer_list<unsigned int>{
		0u,1u,3u,
		2u,1u,3u
	}
	);

	Mesh a;
	a.Init(pos, VERTEX_POS);
	a.Init(color, VERTEX_COLOR_POS);
	a.Init(index);


	ShaderProgram P;
	VertexShader V("resource/vertexShaderCode.vert");
	FragShader F("resource/fragShaderCode.frag");
	V.Compile(P);
	F.Compile(P);



	imgui_window.Init();

	while (!window.IsClose())
	{
		imgui_window.NewFrame();

		glClear(GL_COLOR_BUFFER_BIT);
		P.use();
		a.Render();
		
		imgui_window.Update();
		imgui_window.Render();
		window.SwapBuffer();
		window.PollEvents();
	}


	imgui_window.Shutdown();
	glfwTerminate();

	return 0;
}