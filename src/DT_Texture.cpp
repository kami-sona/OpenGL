#include <DT_Texture.h>

Texture::Texture()
{
	glGenBuffers(1, &TextureID);
}

Texture::Texture(IMAGE_Ptr& Image,GLenum Tex)
{
	glGenTextures(1, &TextureID);
	ImageData = move(Image);

	glActiveTexture(Tex);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	if (ImageData)
	{
		IMAGE_DATA a = ImageData->GetImageInfo();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, a.Width, a.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, a.Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

}


void Texture::_bind()
{
	glBindTexture(GL_TEXTURE_2D, TextureID);
}

void Texture::CreateTexture(string LocationName, string path)
{
	IMAGE_Ptr CurrentImage = make_unique<IMAGE>(path);
	ImageData = move(CurrentImage);

}

Texture::~Texture()
{
	glDeleteBuffers(1, &TextureID);
}