#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;

class Shader;

namespace dt_filestd
{
	class DT_File //This class is to read data from file
	{
		friend class Shader;
	public:
		
		DT_File(string path);


	private:

		string Data;
	};
}

