#pragma once
#include <stb_image.h>
#include <string>
#include <memory>
using namespace std;

typedef struct
{
	int Width;
	int Height;
	int NrChannels;
	unsigned char* Data;
} IMAGE_DATA;//IMGAE的Data的数据结构



class IMAGE
{
public:

	//默认构造函数
	IMAGE() = default;

	//初始化一个IMAGE
	IMAGE(string path);

	//返回IMAGE_DATA
	IMAGE_DATA GetImageInfo();

	~IMAGE();

private:

	//图像的高像素
	int Width;
	//图像的宽像素
	int Height;
	//RGB通道
	int NrChannels;
	//图像的数据
	unsigned char* Data;

};

