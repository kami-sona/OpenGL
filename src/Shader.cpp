#include "Shader.h"

ShaderProgram::ShaderProgram()
{
	ProgramID = glCreateProgram();
}

void ShaderProgram::use()
{
	glLinkProgram(ProgramID);
	glUseProgram(ProgramID);
}

Shader::Shader(string path)
{
	ShaderCode = make_unique<dt_filestd::DT_File>(path);
	ShaderCode_C = ShaderCode->Data.c_str();
}


Shader::~Shader()
{
	glDeleteShader(ShaderID);
}

void Shader::Compile(const ShaderProgram& Pro)
{
	glShaderSource(ShaderID, 1, &ShaderCode_C, nullptr);
	glCompileShader(ShaderID);
	glAttachShader(Pro.ProgramID, ShaderID);
}


VertexShader::VertexShader(string path):Shader(path)
{
	ShaderID = glCreateShader(GL_VERTEX_SHADER);
}

FragShader::FragShader(string path):Shader(path)
{
	ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
}


