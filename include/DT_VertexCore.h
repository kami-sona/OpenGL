#pragma once
#include <glad/glad.h>
#include <vector>
#include <memory>
#include <tuple>
#include <iostream>
using namespace std;
class VBO;
class VAO;

//第一个参数是数据指针，第二个参数是数据大小。第三个数据是数据步长，第三个数据偏移
using DT_VboDataType = tuple<unique_ptr<float[]>, unsigned, unsigned, unsigned, unsigned>;
using DT_VboArryPot = unique_ptr<vector<VBO*>>;

class VerObjBase
{
public:
	virtual void _Bind() = 0;
	virtual void _UnBind() = 0;
	DT_VboDataType _ToOneLine(vector<vector<float>>* TwoDem);//将顶点的数量的数组临时转化为一个一为数组
	virtual void Draw() = 0;
};

class VAO : public VerObjBase
{
public:
	VAO(vector<VBO*>* VBO_set);

	void _Bind() override;

	void _UnBind() override;

	void Draw() override;

	void AddVbo();

	~VAO();
private:
	GLuint VAO_ID;
	DT_VboArryPot VAO_Attr;
};

class VBO : public VerObjBase
{
public:

	VBO(vector<vector<float>>* VBO_data);

	void _Bind() override;

	void _UnBind() override;

	void Draw() override;

	~VBO();

private:
	GLuint VBO_ID;
	unique_ptr<float[]> Vertex_Attr;
	unsigned int Vertex_Size;
	unsigned int Vertex_Offset;
	unsigned int Vertex_Step;
	unsigned int Vertex_Count;
};

