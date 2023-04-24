#pragma once
#include "WindowInfo.h"
#include "DT_File.h"
class DT_Window //This class is to conduct a window 
{
public:

	DT_Window(int width,int height,string name = "window",GLFWmonitor * monitor = nullptr, GLFWwindow* share = nullptr);

	~DT_Window();

	bool IsClose() const;

	void SwapBuffer()const;

	void PollEvents() const;
private:

	GLFWwindow* CWindow;
};

