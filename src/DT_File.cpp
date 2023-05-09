#include "DT_File.h"

DT_File::DT_File(string path)
{
	ifstream file;
	stringstream str_file;
	file.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		file.open(path,ifstream::in);
		str_file << file.rdbuf();
		Data = str_file.str();
	}
	catch (ifstream::failure f)
	{
		cerr << "Exception opening/reading file" << endl;
		cerr << f.what() << endl;
	}
}
