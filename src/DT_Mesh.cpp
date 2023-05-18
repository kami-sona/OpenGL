#include "DT_Mesh.h"

Mesh::Mesh()
{
	Vao_Data = make_unique<VAO>();
}

Mesh::~Mesh()
{

}

void Mesh::Init(DT_VboDataType& Vertex_slot, DT_UVertexLocation Location)
{
	if(Vao_Data)
		Vao_Data->ConverToVertex(Vertex_slot, Location);
}

void Mesh::Init(DT_EboDataType& Vertex_index)
{
	if (Vao_Data)
		Vao_Data->MatchVertex(Vertex_index);
}

void Mesh::Render() const
{
	if (Vao_Data)
		Vao_Data->Draw();
}