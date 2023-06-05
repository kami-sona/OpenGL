#include "WindowInfo.h"
#include "DT_Window.h"
#include "Shader.h"
#include "UsrImgui.h"
#include "DT_Mesh.h"
#include <DT_Texture.h>
#include <DT_Math.h>

int main()
{
	glfwInit();

	DT_Window window(800, 600);

	//bind callback function
	window.SetBufferFresh();

	UsrImgui imgui_window(window.GetWindow(),"#version 130");


	unique_ptr<vector<vector<float>>> pos = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{ -0.5f, -0.5f, -0.5f},
			{ 0.5f, -0.5f, -0.5f },
			{ 0.5f,  0.5f, -0.5f },
			{ 0.5f,  0.5f, -0.5f },
			{ -0.5f,  0.5f, -0.5f },
			{ -0.5f, -0.5f, -0.5f },

			{ -0.5f, -0.5f,  0.5f },
			{ 0.5f, -0.5f,  0.5f},
			{ 0.5f,  0.5f,  0.5f},
			{ 0.5f,  0.5f,  0.5f},
			{ -0.5f,  0.5f,  0.5f},
			{ -0.5f, -0.5f,  0.5f},


			{ -0.5f, 0.5f, 0.5f },
			{ -0.5f, 0.5f, -0.5f},
			{ -0.5f, -0.5f, -0.5f},
			{ -0.5f, -0.5f, -0.5f},
			{ -0.5f, -0.5f, 0.5f},
			{ -0.5f, 0.5f, 0.5f},

			{ 0.5f, 0.5f, 0.5f },
			{0.5f, 0.5f, -0.5f},
			{0.5f, -0.5f, -0.5f},
			{ 0.5f, -0.5f, -0.5f },
			{ 0.5f, -0.5f, 0.5f },
			{ 0.5f, 0.5f, 0.5f },

			{ -0.5f, -0.5f, -0.5f },
			{ 0.5f, -0.5f, -0.5f },
			{ 0.5f, -0.5f, 0.5f },
			{ 0.5f, -0.5f, 0.5f },
			{-0.5f, -0.5f, 0.5f},
			{ -0.5f, -0.5f, -0.5f },

			{ -0.5f, 0.5f, -0.5f },
			{ 0.5f, 0.5f, -0.5f },
			{ 0.5f, 0.5f, 0.5f },
			{ 0.5f, 0.5f, 0.5f },
			{ - 0.5f, 0.5f, 0.5f},
			{ -0.5f, 0.5f, -0.5f }
		}
	);
	

	unique_ptr<vector<vector<float>>> texcord = make_unique<vector<vector<float>>>(
		initializer_list<vector<float>>{
			{0.0,0.0},
			{1.0,0.0},
			{1.0,1.0},
			{1.0,1.0},
			{0.0,1.0},
			{0.0,0.0},

			{0.0,0.0},
			{1.0,0.0},
			{1.0,1.0},
			{1.0,1.0},
			{0.0,1.0},
			{0.0,0.0},

			{1.0,0.0},
			{1.0,1.0},
			{0.0,1.0},
			{0.0,1.0},
			{0.0,0.0},
			{1.0,0.0},

			{1.0,0.0},
			{1.0,1.0},
			{0.0,1.0},
			{0.0,1.0},
			{0.0,0.0},
			{1.0,0.0},

			{0.0,1.0},
			{1.0,1.0},
			{1.0,0.0},
			{1.0,0.0},
			{0.0,0.0},
			{0.0,1.0},

			{0.0,1.0},
			{1.0,1.0},
			{1.0,0.0},
			{1.0,0.0},
			{0.0,0.0},
			{0.0,1.0}
	}
	);




	
	Mesh a;
	a.Init(pos, VERTEX_POS);
	a.Init(texcord, VERTEX_TEX_POS);

	Texture Cube(make_unique<IMAGE>("resource/container.jpg"),GL_TEXTURE0);
	Texture Smile(make_unique<IMAGE>("resource/wotule.jpg"),GL_TEXTURE1);


	ShaderProgram P;
	VertexShader V("resource/vertexShaderCode.vert");
	FragShader F("resource/fragShaderCode.frag");
	P.Compile(&V);
	P.Compile(&F);

	P.SetInt(glGetUniformLocation(P.Get(), "ourTexture"), 0);
	P.SetInt(glGetUniformLocation(P.Get(), "Smlie"), 1);
	

	imgui_window.Init();

	glEnable(GL_DEPTH_TEST);



	while (!window.IsClose())
	{
		imgui_window.NewFrame();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Eigen::Vector3f Tpos = { 0.0,0.0,3.0 };
		Eigen::Matrix4f ModelTransform = DT_Transform::Translate(Tpos);
		ModelTransform = DT_Transform::Rotate(45.0f,Vector3f(1.0,0.0,0.0));


		Eigen::Vector3f CameraPos = { 0.0,0.0,7.0 };
		float newx = sin(PI * (imgui_window.Angle / 180)) * 7.0;
		float newz = cos(PI * (imgui_window.Angle / 180)) * 7.0;
		CameraPos = {newx, 0,newz};
		Eigen::Vector3f Target = { 0.0,0.0,0.0 };
		Eigen::Vector3f Up = { 0.0,1.0,0.0 };
		Eigen::Matrix4f LookAtTransform = DT_Transform::LookAt(CameraPos, Target, Up);



		// 定义投影参数
		int width;
		int height;
		glfwGetFramebufferSize(window.GetWindow(), &width, &height);

		float fov = PI/4; // 视野角度
		float aspectRatio = (float)width / (float)height; // 宽高比
		float nearPlane = 0.1f; // 近平面距离
		float farPlane = 100.0f; // 远平面距离

		Eigen::Matrix4f proj{
			{1 / tan(fov / 2), 0, 0, 0},
			{ 0,1 / tan(fov / 2) * aspectRatio,0,0 },
			{ 0,0,-(farPlane + nearPlane) / (farPlane - nearPlane), (-2 * farPlane * nearPlane) / (farPlane - nearPlane) },
			{ 0,0,-1,0 }
		};



		glUniformMatrix4fv(glGetUniformLocation(P.Get(), "model"), 1, GL_FALSE, ModelTransform.data());
		glUniformMatrix4fv(glGetUniformLocation(P.Get(), "view"), 1, GL_FALSE, LookAtTransform.data());
		glUniformMatrix4fv(glGetUniformLocation(P.Get(), "project"), 1, GL_FALSE, proj.data());

		
		P.use();
		P.SetFloat(glGetUniformLocation(P.Get(), "Mix"), imgui_window.Mix);
		Cube._bind();
		Smile._bind();
		a.Render();

		ModelTransform = DT_Transform::Translate(Vector3f(-2.0, 0.0, 0.0));
		glUniformMatrix4fv(glGetUniformLocation(P.Get(), "model"), 1, GL_FALSE, ModelTransform.data());
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