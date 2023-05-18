#include "DT_Image.h"

IMAGE::IMAGE(string path)
{
	Data = stbi_load(path.c_str(), &Width, &Height, &NrChannels, 0);
}

IMAGE_DATA IMAGE::GetImageInfo()
{
	return IMAGE_DATA{ Width,Height,NrChannels,Data };
}

IMAGE::~IMAGE()
{
}
