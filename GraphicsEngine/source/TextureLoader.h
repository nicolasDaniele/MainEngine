#pragma once

#include <glad/glad.h>
#include <string>

class TextureLoader
{
public:
	TextureLoader() {}
	~TextureLoader() {}

	GLuint GetTextureID(std::string texFileName);
};

