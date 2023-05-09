#include "DT_VertexCore.h"


DT_VboDataType VerObjBase::_ToOneLine(vector<vector<float>>* TwoDem)
{

	unsigned int ElemntCount = 0;
	unsigned int Step = (*TwoDem)[0].size() * sizeof(float);
	unsigned int Offset = 3*sizeof(float);  
	unsigned int Count = 0;

	for (const auto& p : *TwoDem)
	{
		ElemntCount += p.size();
		Count++;
	}
	unique_ptr<float[]> VboData = make_unique<float[]>(ElemntCount);

	unsigned int k = 0;
	for (unsigned i = 0; i < (*TwoDem).size(); i++)
	{
		for (unsigned j = 0; j < (*TwoDem)[i].size(); j++)
		{
			VboData[k] = (*TwoDem)[i][j];	
			if (k < ElemntCount - 1)
				k++;
		}
	}
	cout << endl;

	return make_tuple(move(VboData), ElemntCount, Step, Offset,Count);
}

VAO::VAO(vector<VBO*>*VBO_set)
{
	VAO_Attr = unique_ptr<vector<VBO*>>(VBO_set);
	glGenVertexArrays(1, &VAO_ID);
	glBindVertexArray(VAO_ID);
}

void VAO::AddVbo()
{

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

}



VBO::VBO(vector<vector<float>>* VBO_data)
{
	DT_VboDataType  Calculate = _ToOneLine(VBO_data);
	Vertex_Attr = move(get<0>(Calculate));
	Vertex_Size = get<1>(Calculate);
	Vertex_Step = get<2>(Calculate);
	Vertex_Offset = get<3>(Calculate);
	Vertex_Count = get<4>(Calculate);

	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	glBufferData(GL_ARRAY_BUFFER, Vertex_Size * sizeof(float), Vertex_Attr.get(),GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex_Step, (void*)(Vertex_Offset * 0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Vertex_Step, (void*)(Vertex_Offset * 1));
	glEnableVertexAttribArray(1);
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
	glDrawArrays(GL_TRIANGLES, 0, Vertex_Count);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &VBO_ID);
}