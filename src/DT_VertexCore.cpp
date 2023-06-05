#include "DT_VertexCore.h"


VAO::VAO()
{
	glGenVertexArrays(1, &VAO_ID);
	glBindVertexArray(VAO_ID);
	glGenBuffers(1, &EBO_ID);
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
	if (EBO_data)
		glDrawElements(GL_TRIANGLES, (EBO_data->size()) * sizeof(unsigned int), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, (VBO_Array[VERTEX_POS]->GetCount()) / 3);
}

void VAO::MatchVertex(DT_EboDataType& EBO)
{
	EBO_data = move(EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (EBO_data->size()) * sizeof(unsigned int), EBO_data->data(), GL_STATIC_DRAW);
}

void VAO::ConverToVertex(DT_VboDataType& targrVBO, DT_UVertexLocation Location)
{
	VBO_Array[Location] = make_unique<VBO>(targrVBO, Location);
}


VBO::VBO(DT_VboDataType& VBO_data,DT_UVertexLocation Location)
{
	Vertex_Attr = move(VBO_data);
	VBO_Location = Location;
	Count = (Vertex_Attr->size())*(Vertex_Attr->at(0).size());
	int step = Vertex_Attr->at(0).size();


	std::vector<float> flattenedData;

	// 将所有元素复制到辅助向量中
	for (const auto& innerVec : (*(Vertex_Attr.get()))) {
		flattenedData.insert(flattenedData.end(), innerVec.begin(), innerVec.end());
	}

	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	glBufferData(GL_ARRAY_BUFFER,Count*sizeof(float), flattenedData.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(Location, step, GL_FLOAT, GL_FALSE, step * sizeof(float), (void*)0);
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