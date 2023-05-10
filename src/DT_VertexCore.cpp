#include "DT_VertexCore.h"


VAO::VAO()
{
	glGenVertexArrays(1, &VAO_ID);
	glBindVertexArray(VAO_ID);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &VAO_ID);
}

void VAO::_Bind()
{
	glBindVertexArray(VAO_ID);
}

void VAO::_UnBind()
{
	glBindVertexArray(0);
}

void VAO::Draw()
{
	_Bind();
	glDrawArrays(GL_TRIANGLES,0, (VBO_Array[VERTEX_POS]->GetCount()) / sizeof(float));
}

void VAO::ConverToVertex(DT_VboDataType& targrVBO, DT_UVertexLocation Location)
{
	VBO_Array[Location] = make_unique<VBO>(targrVBO, Location);
}


VBO::VBO(DT_VboDataType& VBO_data,DT_UVertexLocation Location)
{
	Vertex_Attr = move(VBO_data);
	VBO_Location = Location;
	Count = (Vertex_Attr->size())*3;

	std::vector<float> flattenedData;

	// ������Ԫ�ظ��Ƶ�����������
	for (const auto& innerVec : (*(Vertex_Attr.get()))) {
		flattenedData.insert(flattenedData.end(), innerVec.begin(), innerVec.end());
	}

	// ��������������
	const float* dataPtr = flattenedData.data();

	for (size_t i = 0; i < flattenedData.size(); ++i) {
		std::cout << "Data address [" << i << "]: " << (dataPtr + i) << std::endl;
	}

	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	glBufferData(GL_ARRAY_BUFFER,Count*sizeof(float), flattenedData.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(Location, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(Location);
}

void VBO::_Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
}

void VBO::_UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Draw()
{
}

DT_UVertexCount VBO::GetCount() const
{
	return Count;
}

VBO::~VBO()
{
	glDeleteBuffers(1, &VBO_ID);
}