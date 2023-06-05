#pragma once
#include "DT_File.h"
#include "glad/glad.h"

class ShaderProgram;
class Shader;
class VertexShader;
class FragShader;

class ShaderProgram
{
	friend class Shader;
public:

	ShaderProgram();

	void use();

	void Compile(Shader* shader);

	GLuint Get() const;

	void SetInt(GLint Location, GLint value);

	void SetFloat(GLint Location, GLfloat Value);

private:
	GLuint ProgramID;
};

class Shader
{
public:

	Shader(string path);
	virtual ~Shader();


	GLuint ShaderID;
	string ShaderCode;
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



