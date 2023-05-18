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

//��������һ��ָ��˫��vector���ݵ�ָ��
using DT_VboDataType = unique_ptr<vector<vector<float>>>;
//�������Ǵ��붥����ɫ��λ�õ�����
using DT_UVertexLocation = unsigned short;
//������������Ԫ�صĸ���
using DT_UVertexCount = unsigned int;
//��������EBO
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

	//���ɲ���VAO
	VAO();

	//��VAO
	void _Bind() override;

	//���VBO
	void _UnBind() override;

	//����gldrawarrays()
	void Draw() override;

	void MatchVertex(DT_EboDataType & EBO_data);

	//��һ��������һ��DT_VboDataType���ݵ����ã��ڶ�����������Ҫ���붥����ɫ��λ�õĲ���
	//�ú����������Ǵ���һ����λ�ö�Ӧ�ĵ�����λ�ã���ɫ���ݵȣ���Ҫ����һ��VBO���󲢱��浽map��
	void ConverToVertex(DT_VboDataType& targrVBO,DT_UVertexLocation Location);

	~VAO();
private:
	GLuint VAO_ID;
	//VAO��ID

	GLuint EBO_ID;

	DT_EboDataType EBO_data;

	map<unsigned int, unique_ptr<VBO>>VBO_Array;
	//VAO�а������а󶨵�VBO��ͨ���ֵ���ʶ�ӦVBO;
};

class VBO : public VerObjBase
{
public:

	//��һ��������һ��DT_VboDataType���ݵ����ã��ڶ�����������Ҫ���붥����ɫ��λ�õĲ���
	//�ú����������Ǵ���һ����λ�ö�Ӧ�ĵ�����λ�ã���ɫ���ݵ�
	VBO(DT_VboDataType& VBO_data, DT_UVertexLocation Location);

	void _Bind() override;

	void _UnBind() override;

	void Draw() override;

	//��ȡvbo�����е�Ԫ�ظ���
	DT_UVertexCount GetCount()const;


	~VBO();

private:
	GLuint VBO_ID;
	//VBO�����ID

	DT_VboDataType Vertex_Attr;
	//VBO��������ݱ���ָ��

	DT_UVertexLocation VBO_Location;
	//VBO�����ĸ�λ��
	DT_UVertexCount Count;

};

