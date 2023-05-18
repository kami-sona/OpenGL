#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <string>
using namespace std;

typedef struct
{
	int Width;
	int Height;
	int NrChannels;
	unsigned char* Data;
} IMAGE_DATA;

class IMAGE
{
public:
	
	IMAGE() = default;

	IMAGE(string path);

	IMAGE_DATA GetImageInfo();

	~IMAGE();

private:

	int Width;
	int Height;
	int NrChannels;
	unsigned char* Data;
	
};