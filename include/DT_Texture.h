#pragma once
#include <DT_Image.h>
#include <map>
#include <glad/glad.h>

using IMAGE_Ptr = unique_ptr<IMAGE, std::default_delete<IMAGE>>;
//image数据指针，采用默认的删除器

class Texture
{
public:

	//无参构造函数
	Texture();

	//初始化一个纹理，包含它的名字以及指针
	Texture(IMAGE_Ptr& Image, GLenum Tex);

	//切换到当前缓冲
	void _bind();

	//初始化一个纹理
	void CreateTexture(string LocationName,string path);

	~Texture();

private:

	GLuint TextureID;
	IMAGE_Ptr ImageData;
};