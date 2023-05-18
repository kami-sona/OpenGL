#pragma once
#include <DT_VertexCore.h>

using DT_VaoDataType = unique_ptr<VAO>;

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Init(DT_VboDataType& Vertex_slot, DT_UVertexLocation Location);

	void Init(DT_EboDataType& Vertex_index);
;
	void Render() const;
private:

	DT_VaoDataType Vao_Data;//指向VAO的一个指针
};