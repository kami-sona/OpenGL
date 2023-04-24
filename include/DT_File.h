#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

namespace dt_filestd
{
	class DT_File //This class is to read data from file
	{
	public:

		DT_File(string path);


	private:

		string Data;
	};
}

