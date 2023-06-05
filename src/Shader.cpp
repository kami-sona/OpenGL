#include "Shader.h"


ShaderProgram::ShaderProgram()
{
	ProgramID = glCreateProgram();
}

void ShaderProgram::use()
{
	glUseProgram(ProgramID);
}

GLuint ShaderProgram::Get() const
{
	return ProgramID;
}

void ShaderProgram::Compile(Shader* shader)
{
	auto code = shader->ShaderCode.c_str();
	glShaderSource(shader->ShaderID, 1,&code, nullptr);
	glCompileShader(shader->ShaderID);
	glAttachShader(ProgramID, shader->ShaderID);
	glLinkProgram(ProgramID);
}
void ShaderProgram::SetInt(GLint Location, GLint Value)
{
	use();
	glUniform1i(Location, Value);
}

void ShaderProgram::SetFloat(GLint Location, GLfloat Value)
{
	use();
	glUniform1f(Location,Value);
}

Shader::Shader(string path)
{
	ShaderID = 0;
	auto ShaderFile = make_unique<DT_File>(path);
	ShaderCode = ShaderFile->Data;
}


Shader::~Shader()
{
	glDeleteShader(ShaderID);
}


VertexShader::VertexShader(string path):Shader(path)
{
	ShaderID = glCreateShader(GL_VERTEX_SHADER);
}

FragShader::FragShader(string path):Shader(path)
{
	ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
}


