#pragma once
#include "DT_File.h"
#include "glad/glad.h"

class ShaderProgram;
class Shader;

class ShaderProgram
{
	friend class Shader;
public:

	ShaderProgram();

	void use();


	GLuint ProgramID;
};

class Shader
{
public:

	Shader(string path);
	virtual ~Shader();

	virtual void Compile(const ShaderProgram& Pro);

	GLuint ShaderID;
	const char* ShaderCode_C;
	unique_ptr<DT_File>ShaderCode;
};

class VertexShader : public Shader
{
public:

	VertexShader(string path);

};

class FragShader : public Shader
{
public:

	FragShader(string path);

};



