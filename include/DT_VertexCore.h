#pragma once
#include <glad/glad.h>
#include <vector>
#include <memory>
#include <tuple>
#include <iostream>
#include <map>
#define VERTEX_POS 0
#define VERTEX_COLOR_POS 1
#define VERTEX_TEX_POS 2
using namespace std;
class VBO;
class VAO;

//该类型是一个指向双层vector数据的指针
using DT_VboDataType = unique_ptr<vector<vector<float>>>;
//该类型是传入顶点着色器位置的类型
using DT_UVertexLocation = unsigned short;
//该类型是数组元素的个数
using DT_UVertexCount = unsigned int;
//该类型是EBO
using DT_EboDataType = unique_ptr<vector<unsigned int>>;

class VerObjBase
{
public:
	virtual void _Bind() = 0;
	virtual void _UnBind() = 0;
	virtual void Draw() = 0;
};

class VAO : public VerObjBase
{
public:

	//生成并绑定VAO
	VAO();

	//绑定VAO
	void _Bind() override;

	//解绑VBO
	void _UnBind() override;

	//调用gldrawarrays()
	void Draw() override;

	void MatchVertex(DT_EboDataType & EBO_data);

	//第一个参数是一个DT_VboDataType数据的引用，第二个参数是需要传入顶点着色器位置的参数
	//该函数的作用是创建一个与位置对应的单独的位置，颜色数据等，主要创建一个VBO对象并保存到map中
	void ConverToVertex(DT_VboDataType& targrVBO,DT_UVertexLocation Location);

	~VAO();
private:
	GLuint VAO_ID;
	//VAO的ID

	GLuint EBO_ID;

	DT_EboDataType EBO_data;

	map<unsigned int, unique_ptr<VBO>>VBO_Array;
	//VAO中包含所有绑定的VBO，通过字典访问对应VBO;
};

class VBO : public VerObjBase
{
public:

	//第一个参数是一个DT_VboDataType数据的引用，第二个参数是需要传入顶点着色器位置的参数
	//该函数的作用是创建一个与位置对应的单独的位置，颜色数据等
	VBO(DT_VboDataType& VBO_data, DT_UVertexLocation Location);

	void _Bind() override;

	void _UnBind() override;

	void Draw() override;

	//获取vbo数组中的元素个数
	DT_UVertexCount GetCount()const;


	~VBO();

private:
	GLuint VBO_ID;
	//VBO对象的ID

	DT_VboDataType Vertex_Attr;
	//VBO对象的数据本体指针

	DT_UVertexLocation VBO_Location;
	//VBO属于哪个位置
	DT_UVertexCount Count;

};

