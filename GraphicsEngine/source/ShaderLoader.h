#pragma once

#include <glad/glad.h>
#include <string>

class ShaderLoader
{
public:
	GLuint CreateProgram(const char* vertexShaderFilename, const char* fragmentShaderFilename);

private:
	std::string ReadShader(const char* filename);
	GLuint CreateShader(GLenum shaderType, std::string source, const char* shaderName);
};

