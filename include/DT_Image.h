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
} IMAGE_DATA;//IMGAE��Data�����ݽṹ



class IMAGE
{
public:

	//Ĭ�Ϲ��캯��
	IMAGE() = default;

	//��ʼ��һ��IMAGE
	IMAGE(string path);

	//����IMAGE_DATA
	IMAGE_DATA GetImageInfo();

	~IMAGE();

private:

	//ͼ��ĸ�����
	int Width;
	//ͼ��Ŀ�����
	int Height;
	//RGBͨ��
	int NrChannels;
	//ͼ�������
	unsigned char* Data;

};

