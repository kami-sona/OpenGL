#pragma once
#include <DT_Image.h>
#include <map>
#include <glad/glad.h>

using IMAGE_Ptr = unique_ptr<IMAGE, std::default_delete<IMAGE>>;
//image����ָ�룬����Ĭ�ϵ�ɾ����

class Texture
{
public:

	//�޲ι��캯��
	Texture();

	//��ʼ��һ�������������������Լ�ָ��
	Texture(IMAGE_Ptr& Image, GLenum Tex);

	//�л�����ǰ����
	void _bind();

	//��ʼ��һ������
	void CreateTexture(string LocationName,string path);

	~Texture();

private:

	GLuint TextureID;
	IMAGE_Ptr ImageData;
};